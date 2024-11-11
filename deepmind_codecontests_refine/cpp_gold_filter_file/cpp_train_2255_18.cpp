#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
void PA(const T (&a)[N], int n = -1) {
  if (!n) n = N;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << '\n';
}
template <typename T, size_t N, size_t M>
void PA(const T (&a)[N][M], int n, int m) {
  for (int i = 0; i < n; i++) PA(a[i], m);
  cout << '\n';
}
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    if (a.first != b.first)
      return a.first > b.first;
    else
      return a.second < b.second;
  }
};
template <typename T>
T power(T x, int y) {
  if (y == 0) return 1;
  if (x == 0) return 0;
  return x * power(x, y - 1);
}
int n, q, idx;
long long t, arr[200005], sum;
void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
  while (q--) {
    cin >> t;
    sum += t;
    idx = upper_bound(arr, arr + n, sum) - arr;
    if (idx == n) idx = sum = 0;
    cout << n - idx << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
