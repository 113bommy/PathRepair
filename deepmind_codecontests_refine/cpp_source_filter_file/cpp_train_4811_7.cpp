#include <bits/stdc++.h>
using namespace std;
int get_int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long get_ll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double get_db() {
  double x;
  scanf("%lf", &x);
  return x;
}
template <typename T>
int chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  } else
    return 0;
}
template <typename T>
int chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  } else
    return 0;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = (0); i < (v.size()); i++) os << v[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto a : v) os << a << " ";
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v) {
  os << v.first << " " << v.second << " ";
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v) {
  for (auto a : v) cout << a << endl;
  return os;
}
static const int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
static const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
vector<int> G[maxn];
int N, k;
void make_G() {
  for (int i = (0); i < (k); i++) {
    int sz = G[i].size();
    for (int j = (1); j < (sz); j++) {
      G[i][j] = G[i][j - 1];
    }
  }
}
string gene_ans() {
  string ans;
  int sz = G[0].size();
  for (int i = (0); i < (sz); i++) {
    for (int j = (0); j < (k); j++) {
      if (G[i].size() == j) return ans;
      char ch = G[j][i] + '0';
      ans.push_back(ch);
    }
  }
  return ans;
}
int main() {
  cin >> N >> k;
  getchar();
  for (int i = (0); i < (N); i++) {
    char ch = getchar();
    int dig = ch - '0';
    G[i % k].push_back(dig);
  }
  int sz = G[0].size();
  int ok = 0;
  for (int i = (1); i < (sz); i++) {
    for (int j = (0); j < (k); j++) {
      if (G[j].size() == i) {
        ok = 1;
        break;
      }
      if (G[j][i - 1] != G[j][i]) {
        if (G[j][i - 1] > G[j][i]) {
          make_G();
          ok = 1;
          break;
        } else {
          for (int s = k - 1; s >= 0; s--) {
            if (G[s][0] == 9) {
              G[s][0] = 0;
            } else {
              G[s][0]++;
              break;
            }
          }
          make_G();
          ok = 1;
          break;
        }
      }
    }
    if (ok) break;
  }
  cout << N << endl;
  cout << gene_ans() << endl;
  ;
  return 0;
}
