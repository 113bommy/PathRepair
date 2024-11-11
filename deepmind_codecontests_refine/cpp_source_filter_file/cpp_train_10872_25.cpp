#include <bits/stdc++.h>
using namespace std;
bool s[10050];
int main() {
  int n, m;
  cin >> n >> m;
  memset(s, 0, sizeof(s));
  for (int i = 1; i < 102; i++) s[i * i] = 1;
  int a = 0, b = 0, c = 0, d = 0, flag = 0;
  while (flag != 1) {
    a = rand() % 100 + 1;
    b = rand() % 100 + 1;
    c = rand() % 100 + 1;
    d = rand() % 100 + 1;
    int s1, s2, s3, s4;
    s1 = (m - 1) * a * a + b * b;
    s2 = (n - 1) * a * a + c * c;
    s3 = (n - 1) * b * b + d * d;
    s4 = (m - 1) * c * c + d * d;
    if (s[s1] && s[s2] && s[s3] && s[s4]) flag = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      cout << a << ' ';
    }
    cout << b << endl;
  }
  for (int j = 0; j < m - 1; j++) cout << c << ' ';
  cout << d << endl;
  return 0;
}
