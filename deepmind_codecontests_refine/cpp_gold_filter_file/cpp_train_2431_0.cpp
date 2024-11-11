#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5;
const int INF = 1e9 + 7;
long long n, a[MAXN], L[MAXN], R[MAXN], odd[MAXN], Left[MAXN], Right[MAXN];
long long mmax[MAXN], SumOdd[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) cin >> a[i];
  Left[1] = 0;
  for (int i = 2; i <= n; i++) {
    int x = a[i - 1];
    if (x % 2 == 1) x--;
    if (!x)
      Left[i] = 0;
    else {
      Left[i] = Left[i - 1] + x;
    }
  }
  Right[n] = 0;
  for (int i = n - 1; i >= 1; i--) {
    int x = a[i];
    if (x % 2 == 1) x--;
    if (!x)
      Right[i] = 0;
    else {
      Right[i] = Right[i + 1] + x;
    }
  }
  for (int i = 2; i <= n; i++) {
    odd[i - 1] = a[i - 1];
    if (odd[i - 1] % 2 == 0) odd[i - 1]--;
    SumOdd[i] = SumOdd[i - 1] + odd[i - 1];
  }
  mmax[n] = Right[n] + SumOdd[n];
  for (int i = n - 1; i >= 1; i--)
    mmax[i] = max(mmax[i + 1], Right[i] + SumOdd[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, Left[i] - SumOdd[i] + mmax[i]);
  }
  cout << ans;
  return 0;
}
