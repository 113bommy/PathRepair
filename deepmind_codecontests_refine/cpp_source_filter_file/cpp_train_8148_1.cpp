#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int n;
bool calc(long long L, long long R) {
  int id = lower_bound(a, a + n, L) - a;
  if (id == n) return false;
  return a[id] < R;
}
int L(long long b) {
  int ans = 0;
  for (int i = 0; i < 31; i++) {
    if ((b & (1 << i)) && calc(((b >> i) ^ 1) << i, (b >> i) << i)) ans++;
  }
  return ans;
}
int R(long long b) {
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (!(b & (1 << i)) &&
        calc(((b >> i) ^ 1) << i, (((b >> i) ^ 1) << i) + (1 << i)))
      ans++;
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, 1 + L(i) + R(i));
  }
  cout << n - ans << endl;
  return 0;
}
