#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int N = 5009;
const int logN = 20;
const int sqrN = 450;
const int MOD = 100000;
const int INF = 1e9;
const long long INF64 = 1e18;
const long double PI = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
pair<int, int> a[N];
bool u[N];
vector<int> v[N];
vector<int> sum;
void add(int x) {
  while ((int)(sum.size()) < (int)(v[x].size())) sum.push_back(0);
  for (int i = 0; i < (int)((int)(v[x].size())); ++i) sum[i] += v[x][i];
  for (int j = 0; j < (int)((int)(sum.size()) - 1); ++j) {
    sum[j + 1] += sum[j] / MOD;
    sum[j] %= MOD;
  }
  if (sum[(int)(sum.size()) - 1] >= MOD) {
    int j = (int)(sum.size()) - 1;
    int d = sum[j] / MOD;
    sum[j] %= MOD;
    sum.push_back(d);
  }
}
void show() {
  if ((int)(sum.size()) == 0) {
    cout << 0;
    return;
  }
  reverse(sum.begin(), sum.end());
  for (int i = 0; i < (int)((int)(sum.size()) - 1); ++i)
    if (i)
      printf("%05d", sum[i]);
    else
      printf("%d", sum[i]);
}
void calc() {
  v[0].push_back(1);
  for (int i = 1; i < N; ++i) {
    v[i] = v[i - 1];
    for (int j = 0; j < (int)((int)(v[i].size())); ++j) v[i][j] *= 2;
    for (int j = 0; j < (int)((int)(v[i].size()) - 1); ++j) {
      v[i][j + 1] += v[i][j] / MOD;
      v[i][j] %= MOD;
    }
    if (v[i][(int)(v[i].size()) - 1] >= MOD) {
      int j = (int)(v[i].size()) - 1;
      int d = v[i][j] / MOD;
      v[i][j] %= MOD;
      v[i].push_back(d);
    }
  }
}
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  calc();
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    string t;
    int x;
    cin >> t >> x;
    if (t == "win")
      a[i] = make_pair(1, x);
    else
      a[i] = make_pair(0, x);
  }
  for (int x = 2000; x >= 0; --x) {
    int pos = -1;
    for (int i = 0; i < (int)(n); ++i)
      if (a[i].first == 0 && a[i].second == x) pos = i;
    if (pos == -1) continue;
    for (int i = pos; i >= 0; --i) {
      if (u[i]) break;
      if (a[i].first == 1 && a[i].second == x) {
        for (int j = i; j <= pos; ++j) u[j] = true;
        add(x);
        break;
      }
    }
  }
  show();
  return 0;
}
