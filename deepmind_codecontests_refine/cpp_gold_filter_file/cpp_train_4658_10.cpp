#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
template <typename T1, typename T2>
inline void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1>
inline void sort(T1 &arr) {
  sort(arr.begin(), arr.end());
}
template <typename T1>
inline void shuffle(T1 &arr) {
  for (int i = -arr.size(); i < arr.size(); ++i) {
    int first = ((rand() << 16) + rand()) % arr.size(),
        second = ((rand() << 16) + rand()) % arr.size();
    swap(arr[first], arr[second]);
  }
}
template <typename T1>
inline void reverse(T1 &arr) {
  reverse(arr.begin(), arr.end());
}
vector<long long> arr;
vector<bool> used;
long long dfs(long long v) {
  used[v] = true;
  if (!used[arr[v]])
    return dfs(arr[v]) + 1;
  else
    return 1;
}
signed main() {
  long long n;
  cin >> n;
  arr = vector<long long>(n);
  for (auto &i : arr) cin >> i;
  for (auto &i : arr) --i;
  used = vector<bool>(n);
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    if (!used[i]) ans = (ans + (dfs(i) % 2 == 0 ? 1 : 0)) % 2;
  if (ans == (3 * n) % 2)
    cout << "Petr";
  else
    cout << "Um_nik";
  return 0;
}
