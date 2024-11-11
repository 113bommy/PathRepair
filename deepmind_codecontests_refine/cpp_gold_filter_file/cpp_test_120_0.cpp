#include <bits/stdc++.h>
using namespace std;
const int t_max = 1e9 + 7;
const long long MAXX = long long(1e18);
const int INF = int(-1e9);
const double PI = 3.1415926535;
void read() {}
template <typename T1>
void read(T1 v[], int n) {
  for (int i = 0; i < n; i++) cin >> v[i];
}
template <typename T2>
void read(vector<T2>& v, int n) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
template <typename First, typename... Rest>
void read(First& first, Rest&... rest) {
  cin >> first;
  read(rest...);
}
template <typename T3>
void print(vector<T3>& v, int n) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}
template <typename T4>
void print(T4 v[], int n) {
  for (int i = 0; i < n; i++) cout << v[i] << '\n';
}
long long binpow(long long a, long long n, long long k) {
  long long res = 1;
  while (n)
    if (n & 1) {
      res *= a;
      res %= k;
      n--;
    } else {
      a *= a;
      a %= k;
      n >>= 1;
    }
  return res;
}
const int M = 200001, L = 23;
int arr[M][L];
void solve() {
  int l, r;
  cin >> l >> r;
  int maxx = 0;
  for (int i = 0; i < L; i++) maxx = max(maxx, arr[r][i] - arr[l - 1][i]);
  cout << r - l + 1 - maxx << '\n';
}
int main() {
  for (int i = 0; i < L; i++) arr[0][i] = 0;
  for (int i = 1; i < M; i++) {
    for (int j = 0; j < L; j++) arr[i][j] = arr[i - 1][j];
    int k = i;
    int pos = 0;
    while (k != 0) {
      arr[i][pos] += k % 2;
      k /= 2;
      pos++;
    }
  }
  cin.tie(0);
  cout.tie(0);
  std::ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
