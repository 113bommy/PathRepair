#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int a, b = -1, c, d[100007], n, m, T[100007], yasa[100007];
string s, q;
int main() {
  cin >> s >> q;
  n = int(s.size());
  m = int(q.size());
  q += "#" + s;
  for (int i = 1; i < int(q.size()); i++) {
    while (a > 0 && q[i] != q[a]) a = T[a - 1];
    if (q[i] == q[a]) a++;
    T[i] = a;
  }
  for (int i = m + 1; i <= m + n; i++) {
    d[i] = d[i - 1];
    if (T[i] == m) b = i - m;
    if (b != -1) d[i] = d[i] + b - m + 1 + yasa[b], d[i] %= 1000000007;
    yasa[i] = yasa[i - 1] + d[i], yasa[i] %= 1000000007;
  }
  cout << d[m + n] << endl;
  return 0;
}
