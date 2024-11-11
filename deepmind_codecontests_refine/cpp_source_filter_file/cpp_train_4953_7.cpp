#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int n;
int a[1111][1111];
int b[1111][1111];
void output() {
  int cnt = 0;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (i); j++)
      if (a[i][j] == 1) cnt++;
  cout << cnt << endl;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (i); j++)
      if (a[i][j] == 1) cout << i + 1 << ' ' << j + 1 << "\n";
}
int main() {
  int k;
  cin >> n >> k;
  if (k != 2 && k != 3)
    puts("-1");
  else {
    int nm = n * (n - 1) / 2;
    for (int mask = (0); mask < (100); mask++) {
      int pos = 0;
      int type = (k == 3) && n > 50;
      memset(a, -1, sizeof a);
      memset(b, -1, sizeof b);
      for (int i = (0); i < (n); i++) a[i][i] = b[i][i] = 0;
      for (int i = (0); i < (n); i++)
        for (int j = (0); j < (i); j++) {
          int val = rand() % 2;
          if (n > 10 && type) {
            if (i == 1 && j == 0)
              val = 0;
            else if (i == 2 && j == 1)
              val = 0;
            else if (i == 2 && j == 0)
              val = 1;
            else if (i == 6 && j == 5)
              val = 1;
            else if (i == 7 && j == 6)
              val = 1;
            else if (i == 7 && j == 5)
              val = 0;
            else if (j == 0)
              val = 0;
            else if (j == 2)
              val = 1;
          }
          if (val)
            a[i][j] = a[j][i] = 1;
          else
            b[i][j] = b[j][i] = 1;
          pos++;
        }
      if (n > 200) {
        output();
        return 0;
      } else {
        for (int k = (0); k < (n); k++)
          for (int i = (0); i < (n); i++)
            for (int j = (0); j < (n); j++)
              if (a[i][k] != -1 && a[k][j] != -1)
                if (a[i][j] == -1 || a[i][j] > a[i][k] + a[k][j])
                  a[i][j] = a[i][k] + a[k][j];
        for (int k = (0); k < (n); k++)
          for (int i = (0); i < (n); i++)
            for (int j = (0); j < (n); j++)
              if (b[i][k] != -1 && b[k][j] != -1)
                if (b[i][j] == -1 || b[i][j] > b[i][k] + b[k][j])
                  b[i][j] = b[i][k] + b[k][j];
        bool g = 1;
        int d1 = 0, d2 = 0;
        for (int i = (0); i < (n); i++)
          for (int j = (0); j < (n); j++) {
            d1 = max(d1, a[i][j]);
            d2 = max(d2, b[i][j]);
            if (a[i][j] == -1 || b[i][j] == -1) g = 0;
          }
        if (g) {
          int z = min(d1, d2);
          if (z == k) {
            output();
            return 0;
          }
        }
      }
    }
  }
  puts("-1");
  return 0;
}
