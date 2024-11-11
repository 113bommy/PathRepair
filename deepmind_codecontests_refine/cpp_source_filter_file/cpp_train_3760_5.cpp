#include <bits/stdc++.h>
inline long long MAX2(long long a, long long int b) {
  return (a) > (b) ? (a) : (b);
}
inline long long MAX3(long long a, long long b, long long c) {
  return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));
}
inline long long MIN2(long long a, long long b) {
  return (a) < (b) ? (a) : (b);
}
inline long long MIN3(long long a, long long b, long long c) {
  return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));
}
using namespace std;
string ask(int a, int b) {
  string s;
  cout << a << " " << b << '\n';
  cout.flush();
  cin >> s;
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  int x, y;
  int i;
  cin >> n;
  x = 0;
  y = 0;
  int s1 = 0, s2 = 0;
  string s;
  int p = 28;
  char l;
  i = 0;
  while (i < n) {
    i++;
    s = ask(y, 1);
    if (s[0] == 'b')
      s2 = 1;
    else
      s1 = 1;
    if (y == 0) l = s[0];
    if (s1 && s2) break;
    x = y;
    y += pow(2, p--);
  }
  while (i < n) {
    int mid = (x + y) / 2;
    s = ask(mid, 1);
    if (s[0] == l)
      x = mid;
    else
      y = mid;
    i++;
  }
  if (n == 1) {
    cout << "0 0 1 1";
    return 0;
  }
  cout << x << " 0 " << y << " 2";
}
