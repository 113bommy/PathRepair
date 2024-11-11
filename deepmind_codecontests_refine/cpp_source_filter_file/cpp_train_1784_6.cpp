#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, ans;
pair<int, int> foun;
pair<pair<int, int>, pair<int, int> > ke;
string s;
int main() {
  cin >> n >> m;
  ans = n * m;
  int a[n + 10][m + 10];
  for (i = 1; i <= n; i++) {
    cin >> s;
    for (j = 1; j <= m; j++) {
      if (s[j - 1] == 'A') a[i][j] = 1;
      if (s[j - 1] == 'G') a[i][j] = 2;
      if (s[j - 1] == 'C') a[i][j] = 3;
      if (s[j - 1] == 'T') a[i][j] = 4;
    }
  }
  int dyn[5][10][max(n, m) + 10];
  memset(dyn, 0, sizeof(dyn));
  for (j = 1; j <= m; j++)
    for (i = 1; i <= n; i++)
      for (k = 1; k <= 4; k++)
        if (k != a[i][j]) dyn[i & 1][k][j]++;
  int i1, i2, i3, i4;
  for (i1 = 1; i1 <= 4; i1++)
    for (i2 = 1; i2 <= 4; i2++)
      if (i1 != i2)
        for (i3 = 1; i3 <= 4; i3++)
          if (i3 != i1 && i3 != i2) {
            i4 = 10 - i1 - i2 - i3;
            int chg[m + 10];
            memset(chg, 0, sizeof(chg));
            for (j = m; j >= 1; j--)
              if (j & 1)
                chg[j] = chg[j + 1] + min(dyn[1][i1][j] + dyn[0][i3][j],
                                          dyn[0][i1][j] + dyn[1][i3][j]);
              else
                chg[j] = chg[j + 1] + min(dyn[1][i2][j] + dyn[0][i4][j],
                                          dyn[0][i2][j] + dyn[1][i4][j]);
            int val =
                dyn[1][i1][1] + dyn[1][i2][2] + dyn[0][i3][1] + dyn[0][i4][2];
            for (j = 3; j <= m; j++) {
              if (j & 1) {
                ans =
                    min(ans, val + dyn[1][i3][j] + dyn[0][i1][j] + chg[j + 1]);
                if (ans == val + dyn[1][i3][j] + dyn[0][i1][j] + chg[j + 1])
                  foun = {0, j}, ke = {{i1, i2}, {i3, i4}};
              } else {
                ans =
                    min(ans, val + dyn[1][i4][j] + dyn[0][i2][j] + chg[j + 1]);
                if (ans == val + dyn[1][i4][j] + dyn[0][i2][j] + chg[j + 1])
                  foun = {0, j}, ke = {{i1, i2}, {i3, i4}};
              }
              if (j & 1)
                val += dyn[1][i1][j] + dyn[0][i3][j];
              else
                val += dyn[1][i2][j] + dyn[0][i4][j];
            }
            ans = min(ans, val);
            if (ans == val) foun = {0, -1}, ke = {{i1, i2}, {i3, i4}};
          }
  swap(n, m);
  int b[n + 10][m + 10];
  memset(b, 0, sizeof(b));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) b[i][j] = a[j][i];
  memset(dyn, 0, sizeof(dyn));
  for (j = 1; j <= m; j++)
    for (i = 1; i <= n; i++)
      for (k = 1; k <= 4; k++)
        if (k != b[i][j]) dyn[i & 1][k][j]++;
  for (i1 = 1; i1 <= 4; i1++)
    for (i2 = 1; i2 <= 4; i2++)
      if (i1 != i2)
        for (i3 = 1; i3 <= 4; i3++)
          if (i3 != i1 && i3 != i2) {
            i4 = 10 - i1 - i2 - i3;
            int chg[m + 10];
            memset(chg, 0, sizeof(chg));
            for (j = m; j >= 1; j--)
              if (j & 1)
                chg[j] = chg[j + 1] + min(dyn[1][i1][j] + dyn[0][i3][j],
                                          dyn[0][i1][j] + dyn[1][i3][j]);
              else
                chg[j] = chg[j + 1] + min(dyn[1][i2][j] + dyn[0][i4][j],
                                          dyn[0][i2][j] + dyn[1][i4][j]);
            int val =
                dyn[1][i1][1] + dyn[1][i2][2] + dyn[0][i3][1] + dyn[0][i4][2];
            for (j = 3; j <= m; j++) {
              if (j & 1) {
                ans =
                    min(ans, val + dyn[1][i3][j] + dyn[0][i1][j] + chg[j + 1]);
                if (ans == val + dyn[1][i3][j] + dyn[0][i1][j] + chg[j + 1])
                  foun = {1, j}, ke = {{i1, i2}, {i3, i4}};
              } else {
                ans =
                    min(ans, val + dyn[1][i4][j] + dyn[0][i2][j] + chg[j + 1]);
                if (ans == val + dyn[1][i4][j] + dyn[0][i2][j] + chg[j + 1])
                  foun = {1, j}, ke = {{i1, i2}, {i3, i4}};
              }
              if (j & 1)
                val += dyn[1][i1][j] + dyn[0][i3][j];
              else
                val += dyn[1][i2][j] + dyn[0][i4][j];
            }
            ans = min(ans, val);
            if (ans == val) foun = {1, -1}, ke = {{i1, i2}, {i3, i4}};
          }
  i1 = ke.first.first;
  i2 = ke.first.second;
  i3 = ke.second.first;
  i4 = ke.second.second;
  if (foun.first == 1) {
    if (foun.second != -1) {
      for (i = 1; i <= n; i++)
        for (j = 1; j < foun.second; j++)
          if (j & 1)
            if (i & 1)
              b[i][j] = i1;
            else
              b[i][j] = i3;
          else if (i & 1)
            b[i][j] = i2;
          else
            b[i][j] = i4;
      for (i = 1; i <= n; i++)
        if (foun.second & 1)
          if (i & 1)
            b[i][foun.second] = i3;
          else
            b[i][foun.second] = i1;
        else if (i & 1)
          b[i][foun.second] = i4;
        else
          b[i][foun.second] = i2;
      for (j = foun.second + 1; j <= m; j++)
        if (j & 1)
          if (dyn[1][i1][j] + dyn[0][i3][j] > dyn[0][i1][j] + dyn[1][i3][j])
            for (i = 1; i <= n; i++)
              if (i & 1)
                b[i][j] = i1;
              else
                b[i][j] = i3;
          else
            for (i = 1; i <= n; i++)
              if (i & 1)
                b[i][j] = i3;
              else
                b[i][j] = i1;
        else if (dyn[1][i2][j] + dyn[0][i4][j] > dyn[0][i2][j] + dyn[1][i4][j])
          for (i = 1; i <= n; i++)
            if (i & 1)
              b[i][j] = i2;
            else
              b[i][j] = i4;
        else
          for (i = 1; i <= n; i++)
            if (i & 1)
              b[i][j] = i4;
            else
              b[i][j] = i2;
    } else {
      for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
          if (j & 1)
            if (i & 1)
              b[i][j] = i1;
            else
              b[i][j] = i3;
          else if (i & 1)
            b[i][j] = i2;
          else
            b[i][j] = i4;
    }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) a[j][i] = b[i][j];
    swap(n, m);
  } else {
    swap(n, m);
    memset(dyn, 0, sizeof(dyn));
    for (j = 1; j <= m; j++)
      for (i = 1; i <= n; i++)
        for (k = 1; k <= 4; k++)
          if (k != a[i][j]) dyn[i & 1][k][j]++;
    if (foun.second != -1) {
      for (i = 1; i <= n; i++)
        for (j = 1; j < foun.second; j++)
          if (j & 1)
            if (i & 1)
              a[i][j] = i1;
            else
              a[i][j] = i3;
          else if (i & 1)
            a[i][j] = i2;
          else
            a[i][j] = i4;
      for (i = 1; i <= n; i++)
        if (foun.second & 1)
          if (i & 1)
            a[i][foun.second] = i3;
          else
            a[i][foun.second] = i1;
        else if (i & 1)
          a[i][foun.second] = i4;
        else
          a[i][foun.second] = i2;
      for (j = foun.second + 1; j <= m; j++)
        if (j & 1)
          if (dyn[1][i1][j] + dyn[0][i3][j] > dyn[0][i1][j] + dyn[1][i3][j])
            for (i = 1; i <= n; i++)
              if (i & 1)
                a[i][j] = i1;
              else
                a[i][j] = i3;
          else
            for (i = 1; i <= n; i++)
              if (i & 1)
                a[i][j] = i3;
              else
                a[i][j] = i1;
        else if (dyn[1][i2][j] + dyn[0][i4][j] > dyn[0][i2][j] + dyn[1][i4][j])
          for (i = 1; i <= n; i++)
            if (i & 1)
              a[i][j] = i2;
            else
              a[i][j] = i4;
        else
          for (i = 1; i <= n; i++)
            if (i & 1)
              a[i][j] = i4;
            else
              a[i][j] = i2;
    } else {
      for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
          if (j & 1)
            if (i & 1)
              a[i][j] = i1;
            else
              a[i][j] = i3;
          else if (i & 1)
            a[i][j] = i2;
          else
            a[i][j] = i4;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == 1) cout << 'A';
      if (a[i][j] == 2) cout << 'G';
      if (a[i][j] == 3) cout << 'C';
      if (a[i][j] == 4) cout << 'T';
    }
    cout << '\n';
  }
  return 0;
}
