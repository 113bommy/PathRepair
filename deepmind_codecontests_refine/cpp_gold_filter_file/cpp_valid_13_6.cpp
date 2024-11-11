#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
char domino[100][100];
bool vst[100][100];
void solve(int r, int c, int& cnt, bool block) {
  if (vst[r][c]) return;
  vst[r][c] = true;
  if (cnt == 0) {
    if (block) {
      domino[r][c] = domino[r + 1][c] = 'a';
      domino[r][c + 1] = domino[r + 1][c + 1] = 'b';
    } else {
      domino[r][c] = domino[r + 1][c] = 'c';
      domino[r][c + 1] = domino[r + 1][c + 1] = 'd';
    }
  } else {
    if (block) {
      domino[r][c] = domino[r][c + 1] = 'a';
      domino[r + 1][c] = domino[r + 1][c + 1] = 'b';
    } else {
      domino[r][c] = domino[r][c + 1] = 'c';
      domino[r + 1][c] = domino[r + 1][c + 1] = 'd';
    }
    cnt -= 2;
  }
  if (c + 2 > m - 1) {
    if (r + 2 > n - 1) {
      return;
    } else {
      solve(r + 2, c, cnt, !block);
    }
  } else {
    solve(r, c + 2, cnt, !block);
    if (r + 2 < n - 1) solve(r + 2, c, cnt, !block);
  }
}
int main(void) {
  cin >> t;
  for (int test_case = 0; test_case < t; test_case++) {
    memset(domino, 0, sizeof(domino));
    memset(vst, false, sizeof vst);
    cin >> n >> m >> k;
    bool flag = false;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        flag = true;
      }
    } else if (n % 2 == 0) {
      if (m == 1) {
        if (k == 0) {
          flag = true;
        }
      } else {
        if (k % 2 == 0) {
          if (k <= (m - 1) * (n) / 2) {
            flag = true;
          }
        }
      }
    } else {
      if (n == 1) {
        if (k == m * n / 2) {
          flag = true;
        }
      } else {
        if (k >= m / 2) {
          if ((k - m / 2) % 2 == 0) {
            flag = true;
          }
        }
      }
    }
    if (!flag) {
      cout << "NO"
           << "\n";
      continue;
    }
    cout << "YES"
         << "\n";
    if (n % 2 == 0 && m % 2 == 0) {
      solve(0, 0, k, true);
    } else if (n % 2 == 0) {
      bool block = true;
      for (int i = 0; i < n - 1; i += 2) {
        if (block) {
          domino[i][0] = 'e';
          domino[i + 1][0] = 'e';
          block = !block;
        } else {
          domino[i][0] = 'f';
          domino[i + 1][0] = 'f';
          block = !block;
        }
      }
      solve(0, 1, k, true);
    } else {
      bool block = true;
      for (int i = 0; i < m - 1; i += 2) {
        if (block) {
          domino[0][i] = 'e';
          domino[0][i + 1] = 'e';
          block = !block;
        } else {
          domino[0][i] = 'f';
          domino[0][i + 1] = 'f';
          block = !block;
        }
      }
      k -= m / 2;
      solve(1, 0, k, true);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << domino[i][j];
      }
      cout << "\n";
    }
  }
}
