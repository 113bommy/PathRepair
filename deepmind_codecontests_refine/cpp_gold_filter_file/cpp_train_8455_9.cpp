#include <bits/stdc++.h>
int kx[8] = {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8] = {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] = {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] = {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] = {+0, +0, +1, -1};
int dy4[4] = {+1, -1, +0, +0};
long long int gcd(unsigned long long int a, unsigned long long int b) {
  return (a == 0) ? b : gcd(b % a, a);
}
long long int lcm(unsigned long long int a, unsigned long long int b) {
  return a * (b / gcd(a, b));
}
const long long INF = 1e18;
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a[n];
    int earliest[n + 1];
    memset(earliest, -1, sizeof(earliest));
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      if (earliest[a[i]] == -1) {
        earliest[a[i]] = i;
      } else if (earliest[a[i]] < i - 1) {
        cout << "YES\n";
        goto end_of_loop;
      }
    }
    cout << "NO\n";
  end_of_loop:;
  }
}
