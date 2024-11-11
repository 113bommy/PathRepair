#include <bits/stdc++.h>
using namespace std;
long long n, A[100005], d, ans = 0;
long long f(int x) {
  if (x == 0) return 0;
  if (x % 2 == 0) return f(x / 2);
  return f(x / 2) + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    A[i] = f(A[i]);
  }
  sort(A + 1, A + 1 + n);
  d = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i] == A[i + 1])
      d++;
    else {
      ans += d * (d - 1) / 2;
      d = 0;
    }
  }
  cout << ans;
  return 0;
}
