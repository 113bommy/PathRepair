#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int head[100], tail[100];
long long s[100][3][3];
char s1[102], s2[102];
int main() {
  int k, x;
  scanf("%d%d", &k, &x);
  int n, m;
  scanf("%d%d", &n, &m);
  head[1] = 1;
  tail[1] = 1;
  head[2] = 2;
  tail[2] = 2;
  s[1][1][0] = 1;
  s[2][2][0] = 1;
  for (int i = (3); i <= (k); i++) {
    head[i] = head[i - 2];
    tail[i] = tail[i - 1];
    s[i][1][0] = s[i - 2][1][0] + s[i - 1][1][0];
    s[i][2][0] = s[i - 2][2][0] + s[i - 1][2][0];
    s[i][1][1] = s[i - 2][1][1] + s[i - 1][1][1];
    s[i][1][2] = s[i - 2][1][2] + s[i - 1][1][2];
    s[i][2][1] = s[i - 2][2][1] + s[i - 1][2][1];
    s[i][2][2] = s[i - 2][2][2] + s[i - 1][2][2];
    s[i][tail[i - 2]][head[i - 1]]++;
  }
  cerr << s[k][1][0] << endl;
  cerr << s[k][2][0] << endl;
  cerr << s[k][1][1] << endl;
  cerr << s[k][1][2] << endl;
  cerr << s[k][2][1] << endl;
  cerr << s[k][2][2] << endl;
  for (int a11 = (0); a11 <= (1); a11++)
    for (int a12 = (0); a12 <= (1); a12++)
      for (int a21 = (0); a21 <= (1); a21++)
        for (int a22 = (0); a22 <= (1); a22++)
          for (int a1 = (0); a1 <= (n / 2); a1++)
            for (int a2 = (0); a2 <= (m / 2); a2++) {
              if (a1 * s[k][1][0] + a2 * s[k][2][0] + a11 * s[k][1][1] +
                      a12 * s[k][1][2] + a21 * s[k][2][1] + a22 * s[k][2][2] !=
                  x)
                continue;
              fill(s1, s1 + n, 'B');
              fill(s2, s2 + m, 'B');
              if (a11) {
                if (s1[n - 1] == 'C') continue;
                s1[n - 1] = 'A';
                if (s1[0] == 'A') continue;
                s1[0] = 'C';
              }
              if (a22) {
                if (s2[m - 1] == 'C') continue;
                s2[m - 1] = 'A';
                if (s2[0] == 'A') continue;
                s2[0] = 'C';
              }
              if (a12) {
                if (s1[n - 1] == 'C') continue;
                s1[n - 1] = 'A';
                if (s2[0] == 'A') continue;
                s2[0] = 'C';
              }
              if (a21) {
                if (s2[m - 1] == 'C') continue;
                s2[m - 1] = 'A';
                if (s1[0] == 'A') continue;
                s1[0] = 'C';
              }
              if (a1) {
                if (a1 * 2 == n) {
                  if (s1[0] == 'C') continue;
                  s1[0] = 'A';
                  if (s1[n - 1] == 'A') continue;
                  s1[n - 1] = 'C';
                  for (int i = (1); i <= (n - 1); i++)
                    s1[i] = (i % 2) ? 'C' : 'A';
                } else if (a1 * 2 == n - 1) {
                  if (s1[0] != 'C') {
                    for (int i = (0); i <= (n - 2); i++)
                      s1[i] = (i % 2) ? 'C' : 'A';
                  } else if (s1[n - 1] != 'A') {
                    for (int i = (1); i <= (n - 1); i++)
                      s1[i] = (i % 2) ? 'A' : 'C';
                  } else
                    continue;
                } else
                  for (int i = (1); i <= (2 * a1); i++)
                    s1[i] = (i % 2) ? 'A' : 'C';
              }
              if (a2) {
                if (a2 * 2 == m) {
                  if (s2[0] == 'C') continue;
                  s2[0] = 'A';
                  if (s2[m - 1] == 'A') continue;
                  s2[m - 1] = 'C';
                  for (int i = (1); i <= (m - 1); i++)
                    s2[i] = (i % 2) ? 'C' : 'A';
                } else if (a2 * 2 == m - 1) {
                  if (s2[0] != 'C') {
                    for (int i = (0); i <= (m - 2); i++)
                      s2[i] = (i % 2) ? 'C' : 'A';
                  } else if (s2[n - 1] != 'A') {
                    for (int i = (1); i <= (m - 1); i++)
                      s2[i] = (i % 2) ? 'A' : 'C';
                  } else
                    continue;
                } else
                  for (int i = (1); i <= (2 * a2); i++)
                    s2[i] = (i % 2) ? 'A' : 'C';
              }
              cerr << a1 << ' ' << a2 << ' ' << a11 << a12 << a21 << a22
                   << endl;
              puts(s1);
              puts(s2);
              return 0;
            }
  puts("Happy new year!");
  return 0;
}
