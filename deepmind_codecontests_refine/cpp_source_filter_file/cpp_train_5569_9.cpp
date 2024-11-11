#include <bits/stdc++.h>
void quit();
using namespace std;
const long double PI = acos((double)-1.0);
const long double EPS = 1e-11;
double __t;
int n;
long long k;
int a[55];
long long f[55];
void solve(int n, long long k) {
  for (int i = 0; i < (int)n; ++i) a[i] = i + 1;
  for (int i = 0; i < (int)n; ++i) {
    if (k >= f[n - i]) {
      swap(a[i - 1], a[i]);
      k -= f[n - i];
    }
  }
  for (int i = 0; i < (int)n; ++i) cout << a[i] << ' ';
  cout << endl;
}
int main() {
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < 55; i++) f[i] = f[i - 1] + f[i - 2];
  cin >> n >> k;
  solve(n, k);
  quit();
}
void quit() { exit(0); }
