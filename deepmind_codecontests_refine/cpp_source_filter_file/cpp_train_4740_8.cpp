#include <bits/stdc++.h>
using namespace std;
int num[10000];
void de(string s, int b, int c) {
  int a = 0;
  for (int i = 0; i < s.size(); i++) {
    a = a * 10 + s[i] - '0';
  }
  int nu[10] = {0}, x[5], y[5], b1, c1;
  x[1] = a % 10, x[2] = a % 100 / 10, x[3] = a % 1000 / 100,
  x[4] = a % 10000 / 1000;
  for (int i = 1; i <= 4; i++) nu[x[i]] = 1;
  for (int i = 123; i <= 9876; i++) {
    b1 = 0, c1 = 0;
    y[1] = i % 10, y[2] = i % 100 / 10, y[3] = i % 1000 / 100,
    y[4] = i % 10000 / 1000;
    if (y[1] == y[2] || y[1] == y[3] || y[1] == y[4] || y[2] == y[3] ||
        y[2] == y[4] || y[4] == y[3])
      continue;
    for (int j = 1; j <= 4; j++) {
      if (x[j] == y[j])
        b1++;
      else if (nu[y[j]])
        c1++;
    }
    if (b1 == b && c1 == c) {
      num[i]++;
    }
  }
  return;
}
int main() {
  int n, a = 0, b, c, ans = 0, re;
  string s;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s >> b >> c;
    de(s, b, c);
  }
  for (int i = 123; i <= 9876; i++) {
    if (num[i] == n) {
      ans++;
      re = i;
    }
  }
  if (ans == 0)
    cout << "Incorrect data" << endl;
  else if (ans == 1)
    printf("%4d\n", re);
  else
    cout << "Need more data" << endl;
}
