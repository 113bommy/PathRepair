#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0LL) return b;
  return gcd(b, a % b);
}
const int N = 140600;
int B[N];
long long A[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  bool flag = true;
  long long sum = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    sum += (long long)B[i];
  }
  for (int i = 1; i < n; i++) flag = flag & (B[i] == B[i - 1]);
  if (flag) {
    if (B[0] == 0) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) cout << B[i] + 1 << " ";
      cout << "\n";
    } else
      cout << "NO\n";
    return 0;
  }
  B[n] = B[0];
  int pt = -1, prev;
  for (int i = 1; i <= n; i++)
    if (B[i] > B[i - 1]) {
      pt = i;
      break;
    }
  assert(pt != -1);
  if (pt == n) pt = 0;
  prev = pt - 1;
  if (prev < 0) prev = n - 1;
  sum -= (B[pt] + B[prev]);
  long long k = 100000000000000LL * B[pt] + B[prev] + sum;
  A[pt] = B[pt];
  sum = 0;
  for (int i = pt + 1; i < n; i++) {
    A[i] = k - sum;
    sum += B[i];
  }
  for (int i = 0; i < pt; i++) {
    A[i] = k - sum;
    sum += B[i];
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << A[i] << " ";
  cout << "\n";
  return 0;
}
