#include <bits/stdc++.h>
using namespace std;
int n;
int m[1000 + 10][1000 + 10];
bool in(int i) { return i >= 1 and i <= n; }
long long g2(long long n) { return n * (n - 1LL) / 2LL; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    m[x][y] = 1;
  }
  long long cc = 0;
  n = 1000;
  for (int i = 1; i <= n; i++) {
    long long cn = 0;
    long long ii = i;
    long long jj = 1;
    for (; in(ii) and in(jj); ii++, jj++) {
      cn += m[ii][jj];
    }
    cc += g2(cn);
    cn = 0;
    ii = i;
    jj = 1;
    for (; in(ii) and in(jj); ii--, jj++) {
      cn += m[ii][jj];
    }
    cc += g2(cn);
  }
  for (int j = 2; j <= n; j++) {
    long long cn = 0;
    long long ii = 1;
    long long jj = j;
    for (; in(ii) and in(jj); ii++, jj++) {
      cn += m[ii][jj];
    }
    cc += g2(cn);
    cn = 0;
    ii = n;
    jj = 1;
    for (; in(ii) and in(jj); ii--, jj++) {
      cn += m[ii][jj];
    }
    cc += g2(cn);
  }
  cout << cc << "\n";
}
