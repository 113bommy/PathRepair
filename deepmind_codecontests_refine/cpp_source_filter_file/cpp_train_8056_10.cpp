#include <bits/stdc++.h>
using namespace std;
int n;
string d;
long long f[50][50];
long long p10[19];
char w[50][50];
int main() {
  p10[0] = 1;
  for (int i = 1; i <= 18; i++) p10[i] = p10[i - 1] * 10;
  cin >> n >> d;
  f[0][0] = 0;
  for (int i = 1; i <= 2 * n; i++) {
    for (int a = 0; a <= i; a++) {
      int b = i - a;
      if (b > n || a > n) continue;
      int dig = d[i - 1] - '0';
      f[i][a] = 0;
      long long r1 = f[i - 1][a] + dig * p10[n - b],
                r2 = f[i - 1][a - 1] + dig * p10[n - a];
      if (b - 1 >= 0 && r1 >= f[i][a]) {
        f[i][a] = r1;
        w[i][a] = 'H';
      }
      if (a - 1 >= 0 && r2 >= f[i][b]) {
        f[i][a] = r2;
        w[i][a] = 'M';
      }
    }
  }
  string seq;
  for (int i = 2 * n, a = n; i >= 1; i--) {
    seq += w[i][a];
    if (w[i][a] == 'M') a--;
  }
  reverse(seq.begin(), seq.end());
  cout << seq << endl;
  return 0;
}
