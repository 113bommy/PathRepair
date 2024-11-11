#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const unsigned long long LINF = INF * (unsigned long long)INF;
const double EPS = 1e-7;
const int MAX = 20 * 1000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;
const unsigned long long MAS = 1000 * 100;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int a[MAS * 3];
int b[MAS * 3];
int c[MAS * 3];
int used[MAS * 3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int z = 1, x = 0;
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  b[0] = a[0];
  used[0] = 1;
  for (int i = (1); i < (n); i++) {
    if (a[i] != a[i - 1]) {
      b[z] = a[i];
      z++;
      used[i] = 1;
    }
  }
  for (int i = (1); i < (n); i++) {
    if (used[i] != 1) {
      c[x] = a[i];
      x++;
    }
  }
  for (int i = (0); i < (x - 1); i++) {
    if (a[i] == a[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << z << endl;
  sort(b, b + z);
  for (int i = (0); i < (z); i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  cout << x << endl;
  sort(c, c + x);
  reverse(c, c + x);
  for (int i = (0); i < (x); i++) {
    cout << c[i] << " ";
  }
}
