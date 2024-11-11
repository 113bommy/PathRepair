#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 + 100000;
const int MAXA = 5 + 10000;
vector<int> pre;
int arr[MAXN], cont[MAXA];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = (int)0; i < (int)n; ++i) cin >> arr[i];
  for (int i = (int)0; i < (int)MAXA; ++i) {
    if (__builtin_popcount(i) == k) {
      pre.emplace_back(i);
    }
  }
  long long ans = 0LL;
  memset(cont, 0, sizeof cont);
  for (int i = n - 1; ~i; --i) {
    for (const int& x : pre) {
      ans += 1LL * (((x ^ arr[i]) < MAXA) ? cont[x ^ arr[i]] : 0);
    }
    ++cont[arr[i]];
  }
  cout << ans;
  return 0;
}
