#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void print_Number(int n, int len) {
  if (!len) return;
  print_Number(n >> 1, len - 1);
  cout << (n & 1);
}
int countbits1(int n) {
  int cnt = 0;
  while (n) {
    if (n & 1) cnt++;
    n >>= 1;
  }
  return cnt;
}
int getbit(int n, int idx) { return ((n >> idx) & 1) == 1; }
int setbit1(int n, int idx) { return n | (1 << idx); }
int setbit0(int n, int idx) { return n & ~(1 << idx); }
int flipbit(int n, int idx) { return (n ^ (1 << idx)); }
void rotate_number() {
  int n, rotat, ans = 0;
  cin >> n >> rotat;
  print_Number(n, 32);
  cout << "\n";
  while (rotat) {
    if (n & 1)
      ans |= (1 << (32 - rotat));
    else
      ans &= ~(1 << (32 - rotat));
    rotat--;
    n >>= 1;
  }
  int idx = 0;
  while (n) {
    if (n & 1)
      ans |= (1 << idx);
    else
      ans &= ~(1 << idx);
    idx++;
    n >>= 1;
  }
  print_Number(ans, 32);
}
int main() {
  fast();
  int n, x;
  cin >> n >> x;
  if (n == 1) {
    cout << "YES\n";
    cout << x;
  } else if (n == 2 && x == 0)
    cout << "NO\n";
  else if (n == 2 && x > 0) {
    cout << "YES\n";
    cout << 0 << " " << x;
  } else {
    cout << "YES\n";
    int pw = (1 << 17);
    int pw2 = (1 << 18);
    int y = 0;
    for (int i = 1; i <= n - 3; i++) {
      cout << i << " ";
      y ^= i;
    }
    if (y == x)
      cout << pw << " " << pw2 << " " << (pw + pw2);
    else
      cout << pw << " " << ((pw ^ x) ^ y) << " " << 0;
  }
}
