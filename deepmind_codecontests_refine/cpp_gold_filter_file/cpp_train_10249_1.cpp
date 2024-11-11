#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos((long double)-1.0);
const int INF = 1 << 30;
const long long LINF = 1ll << 61;
const int BUFFER_SZ = 1 << 20;
const int MOD = 1000 * 1000 * 1000 + 9;
char BUFFER[BUFFER_SZ];
int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
double gd() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long gll() {
  long long x;
  cin >> x;
  return x;
}
vector<int> gvi(int n) {
  vector<int> a;
  while (n-- > 0) a.push_back(gi());
  return a;
}
string gs() {
  scanf("%s", BUFFER);
  return string(BUFFER);
}
template <class T>
void print(vector<T> &x, string format) {
  format += "%c";
  for (int i = 0; i < x.size(); ++i)
    printf(format.c_str(), x[i], i + 1 == x.size() ? '\n' : ' ');
}
void solve() {
  int n = gi();
  int s = gi();
  vector<vector<pair<int, int>>> Q;
  for (int i = 0; i < n; ++i) {
    int k = gi();
    vector<pair<int, int>> q;
    for (int j = 0; j < k; ++j) {
      int a = gi();
      int b = gi();
      q.push_back(make_pair(a, b));
    }
    Q.push_back(q);
  }
  int res = 0;
  for (int a = 0; a < n; ++a) {
    for (int b = a + 1; b < n; ++b) {
      vector<int> xx;
      int t = 0;
      for (int i = 0; i < Q[a].size(); ++i) {
        t += Q[a][i].second;
        xx.push_back(t);
      }
      int totalA = t;
      t = 0;
      for (int i = 0; i < Q[b].size(); ++i) {
        t += Q[b][i].second;
        xx.push_back(t);
      }
      int totalB = t;
      xx.push_back(0);
      sort((xx).begin(), (xx).end());
      xx.erase(unique((xx).begin(), (xx).end()), xx.end());
      vector<int> D1;
      vector<int> D2;
      int p = 0;
      t = 0;
      int pos = 0;
      for (int i = 0; i < Q[a].size(); ++i) {
        int t2 = t + Q[a][i].second;
        while (p < xx.size() && xx[p] <= t2) {
          D1.push_back(pos + (xx[p] - t) * Q[a][i].first);
          ++p;
        }
        t = t2;
        pos += Q[a][i].first * Q[a][i].second;
      }
      p = 0;
      t = 0;
      pos = 0;
      for (int i = 0; i < Q[b].size(); ++i) {
        int t2 = t + Q[b][i].second;
        while (p < xx.size() && xx[p] <= t2) {
          D2.push_back(pos + (xx[p] - t) * Q[b][i].first);
          ++p;
        }
        t = t2;
        pos += Q[b][i].first * Q[b][i].second;
      }
      int i = 1;
      while (i < D1.size() && i < D2.size()) {
        if (D1[i] < D2[i] && D1[i - 1] > D2[i - 1] ||
            D1[i] > D2[i] && D1[i - 1] < D2[i - 1])
          ++res;
        if (D1[i] == D2[i]) {
          if (i > 0 && i + 1 < D1.size() && i + 1 < D2.size()) {
            if (D1[i + 1] < D2[i + 1] && D1[i - 1] > D2[i - 1] ||
                D1[i + 1] > D2[i + 1] && D1[i - 1] < D2[i - 1])
              ++res;
          }
        }
        ++i;
      }
    }
  }
  printf("%d\n", res);
}
int main() {
  solve();
  return 0;
}
