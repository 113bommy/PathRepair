#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
template <class T>
inline void read(T& res) {
  char c;
  T flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  res *= flag;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int a[105];
void solve(int n) {
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2)
      x++;
    else
      y++;
  }
  if (y != 0) {
    cout << "1" << endl;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        cout << i + 1 << endl;
        break;
      }
    }
  } else if (x < 2)
    cout << -1 << endl;
  else if (2 <= x) {
    int ans1 = -100, ans2 = -100;
    cout << 2 << endl;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 != 0) {
        if (ans1 != -100)
          ans2 = i;
        else
          ans1 = i;
      }
    }
    cout << ans1 + 1 << " " << ans2 + 1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(n);
  }
  return 0;
}
