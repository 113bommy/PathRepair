#include <bits/stdc++.h>
using namespace std;
long long n, m, lx, ly;
long long s[1002000][30];
string x, y;
long long gcd(long long a, long long b) {
  while (b != 0) {
    int c = b;
    b = a % b;
    a = c;
  }
  return a;
}
int main() {
  cin >> m >> n;
  cin >> x;
  cin >> y;
  lx = x.size();
  ly = y.size();
  long long l = gcd(lx, ly);
  long long res = (lx * ly) / l;
  long long L = res;
  for (int i = 0; i <= ly - 1; i++) s[i % l][y[i] - 'a']++;
  for (int i = 0; i <= lx - 1; i++) res -= s[i % l][x[i] - 'a'];
  cout << res * (m * lx / L);
}
