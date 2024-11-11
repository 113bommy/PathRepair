#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000000 + 7;
int addm(int& a, int b) { return (a += b) < mod ? a : a -= mod; }
template <class T, class U>
bool smin(T& a, U b) {
  return a > b ? (a = b, 1) : 0;
}
template <class T, class U>
bool smax(T& a, U b) {
  return a < b ? (a = b, 1) : 0;
}
int n, k;
bool query(int i, int j) {
  cout << 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
  string s;
  cin >> s;
  return s == "NIE";
}
int fnd(int i, int j) {
  if (i == j) return -1;
  if (i + 1 == j) return i;
  if (j - i < 4) {
    for (int c = i + 1; c < j; c++)
      if (query(i, c)) i = c;
    return i;
  }
  int l = 3;
  while (2 * l < j - i) l += 2;
  if (query(i + l / 2, i + l + l / 2))
    return fnd(i + l, j);
  else
    return fnd(i, i + l);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  int a = fnd(0, n);
  int b = fnd(0, a);
  int c = fnd(a + 1, n);
  if (b == -1 || (c != -1 && query(b, c)))
    cout << 2 << ' ' << a + 1 << ' ' << c + 1 << endl;
  else
    cout << 2 << ' ' << a + 1 << ' ' << b + 1 << endl;
}
