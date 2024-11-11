#include <bits/stdc++.h>
using namespace std;
const int size1 = 8e5 + 500;
const int INF = 1e9;
const double eps = 1e-5;
static bool used[size1];
static int bor[size1][2];
void dfs(int v, int ur) {
  if (ur == 20) {
    used[v] = true;
  } else {
    used[v] = true;
    if (bor[v][0]) {
      dfs(bor[v][0], ur + 1);
      used[v] &= used[bor[v][0]];
    } else {
      used[v] = false;
    }
    if (bor[v][1]) {
      dfs(bor[v][1], ur + 1);
      used[v] &= used[bor[v][1]];
    } else {
      used[v] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, i, j;
  cin >> n >> q;
  int len = 1;
  static int mas[size1];
  for (i = 1; i <= n; i++) {
    cin >> mas[i];
    int pos = 1;
    for (j = 19; j >= 0; j--) {
      if (mas[i] >= (1 << j)) {
        mas[i] -= (1 << j);
        if (bor[pos][1] == 0) {
          len++;
          bor[pos][1] = len;
          pos = len;
        } else {
          pos = bor[pos][1];
        }
      } else {
        if (bor[pos][0] == 0) {
          len++;
          bor[pos][0] = len;
          pos = len;
        } else {
          pos = bor[pos][0];
        }
      }
    }
  }
  dfs(1, 0);
  int xor1 = 0;
  int k;
  for (i = 1; i <= q; i++) {
    int x;
    cin >> x;
    xor1 = (xor1 ^ x);
    int ch = 0;
    int pos = 1;
    for (j = 19; j >= 0; j--) {
      if (xor1 & (1 << j)) {
        if (bor[pos][1] == 0) {
          for (k = j; k >= 0; k--) {
            if (xor1 & (1 << k)) {
              ch += (1 << k);
            }
          }
          cout << (ch ^ xor1) << "\n";
          break;
        }
        if (!used[bor[pos][1]]) {
          pos = bor[pos][1];
          ch += (1 << j);
        } else {
          if (bor[pos][0] == 0) {
            for (k = j - 1; k >= 0; k--) {
              if (xor1 & (1 << k)) {
                ch += (1 << k);
              }
            }
            cout << (ch ^ xor1) << "\n";
            break;
          } else {
            pos = bor[pos][0];
          }
        }
      } else {
        if (bor[pos][0] == 0) {
          for (k = j; k >= 0; k--) {
            if (xor1 & (1 << k)) {
              ch += (1 << k);
            }
          }
          cout << (ch ^ xor1) << "\n";
          break;
        }
        if (!used[bor[pos][0]]) {
          pos = bor[pos][0];
        } else {
          if (bor[pos][1] == 0) {
            ch += (1 << j);
            for (k = j - 1; k >= 0; k--) {
              if (xor1 & (1 << k)) {
                ch += (1 << k);
              }
            }
            cout << (ch ^ xor1) << "\n";
            break;
          } else {
            ch += (1 << j);
            pos = bor[pos][0];
          }
        }
      }
    }
  }
  return 0;
}
