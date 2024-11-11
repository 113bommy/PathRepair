#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000000;
template <class T>
inline void read(T &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag *= -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= flag;
  return;
}
int ask(int x) {
  cout << "? " << x << endl;
  int response;
  cin >> response;
  return response;
}
inline void ans(int x) {
  cout << "! " << x << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 4) return cout << "! -1\n", 0;
  int st = ask(1);
  int ed = ask(n / 2 + 1);
  if (st == ed) ans(1);
  int l = 1, r = n / 2;
  while (l < r) {
    int mid = (l + r) >> 1;
    int a = ask(mid);
    int b = ask((mid + n / 2 - 1) % n + 1);
    if (a == b) ans(mid);
    if (st > ed) {
      if (a < b)
        r = mid - 1;
      else
        l = mid + 1;
    } else {
      if (a > b)
        r = mid - 1;
      else
        l = mid + 1;
    }
  }
  ans(l + 1);
}
