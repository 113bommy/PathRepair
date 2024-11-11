#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  bool sheep = false;
  while (T--) {
    if (sheep)
      cout << endl;
    else
      sheep = true;
    int n, m, k;
    cin >> n >> m >> k;
    int max = 4 * (n - 1) * (m - 1);
    int gap = max - k;
    if (k > 4 * (n - 1) * (m - 1)) {
      cout << -1 << endl;
      continue;
    }
    if (k == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == 0 and j == 0)
            cout << "*";
          else
            cout << ".";
        }
        cout << endl;
      }
      continue;
    }
    if (gap == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << "*";
        }
        cout << endl;
      }
      continue;
    }
    if (gap == 1 or gap == 2 or gap == 4 or gap == 5) {
      cout << -1 << endl;
      continue;
    }
    if (gap == 3) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == n - 1 and j == m - 1)
            cout << ".";
          else
            cout << "*";
        }
        cout << endl;
      }
      continue;
    }
    if (gap == 6) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == n - 2 and j == m - 1)
            cout << ".";
          else
            cout << "*";
        }
        cout << endl;
      }
      continue;
    }
    if (gap == 7) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if ((i == n - 2 or i == n - 1) and j == m - 1)
            cout << ".";
          else
            cout << "*";
        }
        cout << endl;
      }
      continue;
    }
    if (gap == 8) {
      if (m > 3 and n > 3) {
        cout << -1 << endl;
        continue;
      } else {
        if (m == 3)
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              if (i == n - 1)
                cout << ".";
              else
                cout << "*";
            }
            cout << endl;
          }
        else
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              if (j == m - 1)
                cout << ".";
              else
                cout << "*";
            }
            cout << endl;
          }
      }
      continue;
    }
    if (gap == 12) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == n - 2 and j == m - 2)
            cout << ".";
          else
            cout << "*";
        }
        cout << endl;
      }
      continue;
    }
    bool a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = false;
      }
    }
    for (int i = 0; i < m - 1; i++) {
      a[1][i] = true;
    }
    int maxOne = 4 * ((m - 2) * (n - 2) - 1) + 1 + 3;
    int maxTwo = maxOne + 4 * ((m - 4) * (m > 3) + (n - 4) * (n > 3)) +
                 (m > 3) + (n > 3);
    int maxThree = maxTwo + 3;
    int maxFour = maxThree + 3 * (m > 3);
    if (k <= maxOne) {
      int squares = (k - 1) / 4;
      int residue = (k - 1) % 4;
      int s = 0;
      while (squares--) {
        a[s / (m - 2) + 2][m - s % (m - 2) - 3] = true;
        s++;
      }
      for (int i = 1; i < n - 1; i++) {
        if (a[i][0]) a[i + 1][m - 2] = true;
      }
      if (residue == 1) {
        a[0][m - 2] = true;
      } else if (residue == 2) {
        a[0][m - 2] = true;
        a[0][m - 1] = true;
      } else if (residue == 3) {
        a[0][m - 2] = true;
        a[1][m - 1] = true;
      }
    } else if (k <= maxTwo) {
      int residue = (k - (m > 3) - (n > 3) - 1) % 4;
      int bonusSquares = (k - maxOne + 3 - (m > 3) - (n > 3)) / 4;
      int ii = n - 2;
      int jj = 1;
      while (bonusSquares--) {
        if (jj < m - 3) {
          a[0][jj] = true;
          jj++;
        } else if (ii > 2) {
          a[ii][m - 1] = true;
          ii--;
        }
      }
      if (m > 3) {
        a[0][0] = true;
      }
      if (n > 3) {
        a[n - 1][m - 1] = true;
      }
      if (residue == 1) {
        a[0][m - 2] = true;
      } else if (residue == 2) {
        a[0][m - 2] = true;
        a[0][m - 1] = true;
      } else if (residue == 3) {
        a[0][m - 2] = true;
        a[1][m - 1] = true;
      }
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
          if (i != n - 1 or j != 0) a[i][j] = true;
        }
      }
    } else if (k <= maxThree) {
      a[n - 1][0] = true;
      int residue = (k - maxTwo) % 4;
      if (residue == 1) {
        a[0][m - 2] = true;
      } else if (residue == 2) {
        a[0][m - 2] = true;
        a[0][m - 1] = true;
      } else if (residue == 3) {
        a[0][m - 2] = true;
        a[1][m - 1] = true;
      }
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
          a[i][j] = true;
        }
      }
      for (int i = n - 1; i > 2; i--) {
        a[i][m - 1] = true;
      }
      for (int i = 0; i < m - 3; i++) {
        a[0][i] = true;
      }
      if (m > 3) {
        a[0][0] = true;
      }
      if (n > 3) {
        a[n - 1][m - 1] = true;
      }
    } else if (k <= maxFour) {
      a[0][m - 3] = true;
      int gapFour = k - maxThree - 1;
      if (gapFour > 0) a[1][m - 1] = true;
      if (gapFour > 1) a[0][m - 1] = true;
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
          a[i][j] = true;
        }
      }
      for (int i = n - 1; i > 2; i--) {
        a[i][m - 1] = true;
      }
      for (int i = 0; i < m - 3; i++) {
        a[0][i] = true;
      }
    } else if (k <= (maxFour + 3)) {
      a[0][m - 3] = true;
      a[0][m - 2] = true;
      int gapFive = k - maxFour - 1;
      if (gapFive == 1)
        a[0][m - 1] = true;
      else if (gapFive == 2)
        a[1][m - 1] = true;
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
          a[i][j] = true;
        }
      }
      for (int i = n - 1; i > 2; i--) {
        a[i][m - 1] = true;
      }
      for (int i = 0; i < m - 3; i++) {
        a[0][i] = true;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j])
          cout << "*";
        else
          cout << ".";
      }
      cout << endl;
    }
  }
  return 0;
}
