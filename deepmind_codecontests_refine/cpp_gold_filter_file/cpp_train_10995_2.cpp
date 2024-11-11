#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:2000000")
using namespace std;
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 2e5 + 5, LG = 19, MOD = 998244353;
const int SQ = 320;
const long double EPS = 1e-7;
void printCase(int cs) { cout << "Case #" << cs << ": "; }
int n;
vector<ii> arr;
int mx[3005][3005];
void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(ii(x, i));
  }
  sort(arr.rbegin(), arr.rend());
  arr.push_back(ii(0, n));
}
int getVal(int i) { return arr[i].first - arr[i + 1].first; }
void initMax() {
  for (int i = 0; i < n; i++) {
    mx[i][i] = i;
    for (int j = i + 1; j < n; j++) {
      mx[i][j] = mx[i][j - 1];
      if (getVal(j) > getVal(mx[i][j])) {
        mx[i][j] = j;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read();
  initMax();
  vector<int> ans(6, INT_MIN);
  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j++)
      if (i <= (j - i + 1) * 2 && i * 2 >= (j - i + 1)) {
        int mn = min(j - i + 1, i);
        int mx = max(j - i + 1, i);
        int r = mn * 2;
        int l = (mx + 1) / 2;
        if (j + l < n) {
          int k = ::mx[j + l][min(n - 1, j + r)];
          vector<int> v({getVal(i - 1), getVal(j), getVal(k), i, j + 1, k + 1});
          ans = max(ans, v);
        }
      }
  vector<int> out(n, -1);
  for (int i = 0; i < ans[3]; i++) out[arr[i].second] = 1;
  for (int i = ans[3]; i < ans[4]; i++) out[arr[i].second] = 2;
  for (int i = ans[4]; i < ans[5]; i++) out[arr[i].second] = 3;
  for (int i = 0; i < n; i++) cout << out[i] << " \n"[i + 1 == n];
  return 0;
}
