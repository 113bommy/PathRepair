#include <bits/stdc++.h>
using namespace std;
bool pri(int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long c[300000], a[300000], b[300000], d[300000], e[300000];
int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '5') {
      a[2]++;
      continue;
    }
    if (s[i] == '9') {
      a[6]++;
      continue;
    }
    a[int(s[i]) - int('0')]++;
  }
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '5') {
      b[2]++;
      continue;
    }
    if (t[i] == '9') {
      b[6]++;
      continue;
    }
    b[int(t[i]) - int('0')]++;
  }
  long long o = 400000;
  for (int i = 0; i < 10; i++) {
    if (a[i]) o = min(o, b[i] / a[i]);
  }
  cout << o;
  return 0;
}
