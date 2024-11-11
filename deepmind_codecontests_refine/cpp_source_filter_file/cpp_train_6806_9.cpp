#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], L[N], R[N];
void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
}
void solve() {
  for (int i = 0; i < n; i++) {
    L[i] = i - 1;
    while (~L[i] && a[L[i]] <= a[i]) L[i] = L[L[i]];
  }
  for (int i = n - 1; ~i; i--) {
    R[i] = i + 1;
    while (R[i] < n && a[R[i]] <= a[i]) R[i] = R[R[i]];
  }
}
void write_output() {
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (auto x : {L[i], R[i]})
      if (~x && x < n) ans = max(ans, a[i] | a[x]);
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
