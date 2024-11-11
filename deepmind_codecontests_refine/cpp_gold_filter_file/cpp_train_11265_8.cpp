#include <bits/stdc++.h>
using namespace std;
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long oo = 1e18;
const long long maxN = 1e6;
void maximize(int &a, int b) { a = max(a, b); }
void minimize(int &a, int b) { a = min(a, b); }
int a[maxN], L[maxN], R[maxN];
void solve() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) L[i] = R[i] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) L[i] = L[i - 1] + 1;
    ans = max(ans, L[i]);
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] < a[i + 1]) R[i] = R[i + 1] + 1;
    ans = max(ans, R[i]);
  }
  for (int i = 2; i < n; i++) {
    if (a[i - 1] < a[i + 1]) {
      ans = max(ans, L[i - 1] + R[i + 1]);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
