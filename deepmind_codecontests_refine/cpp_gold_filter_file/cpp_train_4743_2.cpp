#include <bits/stdc++.h>
using namespace std;
int a[(1 << 19)];
void add(long long s, int v) {
  int p = 0, i = 0;
  while (i < 18) {
    p = 2 * p + (s & 1);
    s = s / 10;
    i++;
  }
  a[p] = a[p] + v;
}
int tfind(long long s) {
  int p = 0, i = 0;
  while (i < 18) {
    p = 2 * p + (s & 1);
    s = s / 10;
    i++;
  }
  return a[p];
}
int main() {
  int t;
  for (cin >> t; t > 0; t--) {
    char ch;
    long long s;
    cin >> ch;
    cin >> s;
    if (ch == '+') {
      add(s, 1);
    } else if (ch == '-') {
      add(s, -1);
    } else if (ch == '?') {
      cout << tfind(s) << endl;
    }
  }
  return 0;
}
