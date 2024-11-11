#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) {
  if (n == 1) {
    return 1;
  }
  return n * fact(n - 1);
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long finddigit(long long n) {
  long long f = 0;
  while (n != 0) {
    f++;
    n = n / 10;
  }
  return --f;
}
long long countSetBits(long long n) {
  long long count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
void work() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "-1";
    return;
  }
  for (long long i = 1; i < n; i++) {
    cout << "8";
  }
  cout << "5";
}
signed main() {
  fast();
  long long t;
  cin >> t;
  while (t--) {
    work();
    cout << "\n";
  }
  return 0;
}
