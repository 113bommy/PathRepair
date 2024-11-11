#include <bits/stdc++.h>
bool f(int x, int y) { return x > y; }
using namespace std;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
bool isPrime(long long n) {
  bool ans = 1;
  for (long long i = 2; i <= (sqrt(n)); i++) {
    if (n % i == 0) {
      ans = 0;
      break;
    }
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0)
    cout << "NO";
  else {
    cout << "YES\n";
    vector<long long> ans(2 * n);
    long long k = 1;
    long long i = 0;
    long long forward = 1;
    while (i < (2 * n)) {
      ans[i] = k;
      k++;
      if (forward == 1) {
        ans[i + n] = k;
        k++;
        forward = 0;
        i += n + 1;
      } else {
        ans[i - n] = k;
        k++;
        forward = 1;
        i = i - n + 1;
      }
    }
    for (long long x : ans) cout << x << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
}
