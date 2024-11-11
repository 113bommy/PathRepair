#include <bits/stdc++.h>
using namespace std;
long long f[1 << 18][101];
bool bit(int x, int i) { return ((x >> i) & 1); }
int bit1(int x, int i) { return (x | (1 << i)); }
inline long long fac(int k) {
  int ans = 1, i;
  for (i = 1; i <= k; i++) {
    ans *= i;
  }
  return ans;
}
int C[100];
int main() {
  int cnt = 0;
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<int> a;
  a.resize((int)s.length());
  for (int i = 0; i < (int)s.length(); ++i) {
    a[i] = s[i] - '0';
    C[a[i]]++;
  }
  long long n = (int)a.size();
  f[0][0] = 1;
  for (int bmp = 0; bmp < (1 << ((int)a.size())); ++bmp) {
    for (int k = 0; k < m; ++k) {
      for (int i = 0; i < n; ++i)
        if (!bit(bmp, i)) {
          int new_bmp = bit1(bmp, i);
          if (bmp != 0 || a[i] != 0)
            f[new_bmp][(10 * k + a[i]) % m] += f[bmp][k];
        }
    }
  }
  long long ans = f[(1 << (n)) - 1][0];
  for (int i = 0; i <= 9; i++) {
    ans = ans / fac(C[i]);
  }
  cout << ans;
  return 0;
}
