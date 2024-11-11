#include <bits/stdc++.h>
using namespace std;
long long exp_pow(long long n, long long a) {
  if (a == 0) return 1;
  long long p = exp_pow(n, a >> 1);
  if (a % 2 == 0) return p * p;
  return p * p * n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k % 3) {
      if (n % 3 == 0)
        cout << "Bob" << endl;
      else
        cout << "Alice" << endl;
    } else {
      long long a = n % (k + 1);
      if (a == 0 || a % 3 == 0 && a <= k - 3)
        cout << "Bob" << endl;
      else
        cout << "Alice" << endl;
    }
  }
  return 0;
}
