#include <bits/stdc++.h>
inline void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
inline int ABS(int a) { return a < 0 ? -a : a; }
using namespace std;
long long module = 1e9 + 7;
char c[3][1005];
int state[250][250];
bool one[250];
long long two[250];
long long rez[250];
long long dinTwo[250];
int n, m;
int main() {
  cin >> n >> m;
  cin >> c[0];
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != 3; j++) {
      cin >> c[j];
    }
    for (int j = 0; j != m; j++) {
      int mask = 0;
      int idx = 0;
      for (int x = 0; x != 3; x++)
        for (int z = 0; z != 3; z++) {
          if (c[x][j * 4 + 1 + z] == 'O') {
            mask |= 1 << idx;
          }
          idx++;
        }
      if (mask == 0 || mask == 16 || mask == 341 || mask == 325)
        state[i][j] = 0;
      else if (mask == 455 || mask == 257 || mask == 273)
        state[i][j] = 1;
      else
        state[i][j] = 2;
    }
    cin >> c[0];
  }
  if (!(n % 2)) {
    for (int i = 0; i != m; i++) {
      bool ok = true;
      for (int j = 0; j != n; j++) {
        if (state[i][j] == 1) {
          ok = false;
          break;
        }
      }
      one[i] = ok;
    }
  }
  int m2 = m - 1;
  for (int i = 0; i != m2; i++) {
    dinTwo[0] = !((state[0][i] | state[0][i + 1]) & 2);
    if (n != 1) {
      dinTwo[1] = !(
          (state[0][i] | state[0][i + 1] | state[1][i] | state[1][i + 1]) & 1);
      if (dinTwo[0]) {
        if (!((state[1][i] | state[1][i + 1]) & 2)) {
          dinTwo[1]++;
        }
      }
    }
    for (int j = 2; j < n; j++) {
      dinTwo[j] = 0;
      if (!((state[j][i] | state[j][i + 1] | state[j - 1][i] |
             state[j - 1][i + 1]) &
            1)) {
        dinTwo[j] += dinTwo[j - 2];
      }
      if (!((state[j][i] | state[j][i + 1]) & 2)) {
        dinTwo[j] += dinTwo[j - 1];
      }
      dinTwo[j] %= module;
    }
    two[i] = dinTwo[n - 1];
  }
  rez[0] = one[0];
  rez[1] = two[0] + (one[1] ? rez[0] : 0) - (one[1] & one[0] ? rez[0] : 0);
  for (int j = 2; j < m; j++) {
    rez[j] = two[j - 1] * rez[j - 2] + one[j] * rez[j - 1] -
             one[j] * one[j - 1] * rez[j - 2];
    rez[j] %= module;
  }
  cout << rez[m - 1] << endl;
  return 0;
}
