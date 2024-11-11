#include <bits/stdc++.h>
using namespace std;
int k[1000][1000], m, x = 1;
string s[1000], h;
bool mark[5];
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  mark[1] = 1;
  for (int i = 0; i < n; i++) {
    if (x >= n) {
      cout << m;
      break;
    }
    if (a <= b && mark[1] == 1) {
      m = m + a;
      mark[1] = 0;
      mark[2] = 1;
      x++;
    }
    if (x >= n) {
      cout << m;
      break;
    }
    if (a <= c && mark[2] == 1) {
      m = m + a;
      mark[2] = 0;
      mark[1] = 1;
      x++;
    }
    if (x >= n) {
      cout << m;
      break;
    }
    if (b <= a && mark[1] == 1) {
      m = m + b;
      mark[1] = 0;
      mark[3] = 1;
      x++;
    }
    if (x >= n) {
      cout << m;
      break;
    }
    if (c <= a && mark[2] == 1) {
      m = m + c;
      mark[2] = 0;
      mark[3] = 1;
      x++;
    }
    if (x >= n) {
      cout << m;
      break;
    }
    if (b <= c && mark[3] == 1) {
      m = m + b;
      mark[3] = 0;
      mark[1] = 1;
      x++;
    }
    if (x >= n) {
      cout << m;
      break;
    }
    if (c <= b && mark[3] == 1) {
      m = m + c;
      mark[3] = 0;
      mark[2] = 1;
      x++;
    }
    if (x >= n) {
      cout << m;
      break;
    }
  }
}
