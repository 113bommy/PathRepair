#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000002;
const long long INFLL = 100000000000000000ll;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
template <class T>
T md(T x, T mymod) {
  if (x >= mymod) x -= mymod;
  if (x < 0) x += mymod;
  return x;
}
template <class T>
T LCM(T a, T b) {
  return a * b / __gcd(a, b);
}
template <class T>
T ceil_div(T a, T b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}
template <class T>
string NumToString(T n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
template <class T>
T StringToNum(string s) {
  stringstream geek(s);
  T x = 0;
  geek >> x;
  return x;
}
int r1, r2, c1, c2, d1, d2;
int a[6];
int check = 0;
void Try(int i) {
  for (int j = 1; j <= 9; j++) {
    if (find(a, a + 4, j) == a + 4) {
      a[i] = j;
      if (i == 4) {
        if (a[0] + a[1] == r1 && a[2] + a[3] == r2 && a[0] + a[2] == c1 &&
            a[1] + a[3] == c2 && a[0] + a[3] == d1 && a[1] + a[2] == d2) {
          check = 1;
          return;
        }
      }
      Try(i + 1);
      a[i] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  long n;
  cin >> n;
  vector<long> a;
  long ans = n;
  long s1, s2;
  for (long i = 1; i <= n / 2; i++) {
    if (n % i == 0) {
      if ((max(n / i, i) - min(n / i, i)) < ans) {
        ans = (max(n / i, i) - min(n / i, i));
        s1 = n / i;
        s2 = i;
      }
    }
  }
  cout << min(s1, s2) << " " << max(s1, s2);
  return 0;
}
