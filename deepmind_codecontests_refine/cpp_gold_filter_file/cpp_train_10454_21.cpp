#include <bits/stdc++.h>
using namespace std;
inline long FastMax(long x, long y) {
  return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y;
}
inline long FastMin(long x, long y) {
  return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x;
}
int K, n, m, x;
long long fib[60];
char s1[107], s2[107];
bool check(int t1, int t2) {
  long long tot = t1 + t2;
  if (tot > x) return false;
  char st1 = s1[0];
  char en1 = s1[n - 1];
  char st2 = s2[0];
  char en2 = s2[m - 1];
  long long f1 = t1;
  long long f2 = t2;
  long long f3;
  char st3, en3;
  for (int i = 3; i <= K; i++) {
    if (tot > x) return false;
    f3 = f1 + f2;
    if (en1 == 'A' && st2 == 'C') f3++;
    st3 = st1;
    en3 = en2;
    st1 = st2;
    en1 = en2;
    st2 = st3;
    en2 = en3;
    f1 = f2;
    f2 = f3;
    tot = f3;
  }
  if (tot == x) return true;
  return false;
}
int main() {
  scanf("%d%d%d%d", &K, &x, &n, &m);
  bool pl = false;
  s1[n] = 0;
  s2[m] = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (i <= 2) {
        s1[0] = 'A';
      } else if (i > 2 && i <= 5)
        s1[0] = 'C';
      else if (i > 5)
        s1[0] = 'D';
      if (j <= 2)
        s2[0] = 'A';
      else if (j > 2 && j <= 5)
        s2[0] = 'C';
      else if (j > 5)
        s2[0] = 'D';
      if (i % 3 == 0 && n > 1)
        s1[n - 1] = 'A';
      else if (i % 3 == 1 && n > 1)
        s1[n - 1] = 'C';
      else if (n > 1)
        s1[n - 1] = 'D';
      if (j % 3 == 0 && m > 1)
        s2[m - 1] = 'A';
      else if (j % 3 == 1 && m > 1)
        s2[m - 1] = 'C';
      else if (m > 1)
        s2[m - 1] = 'D';
      for (int l1 = 0; l1 <= n / 2 + 1; l1++)
        for (int l2 = 0; l2 <= m / 2 + 1; l2++) {
          int t1 = 0;
          int t2 = 0;
          if (n == 2) {
            if (s1[0] == 'A' && s1[n - 1] == 'C') t1++;
          }
          for (int k = 1; k < n - 1; k++) {
            if (s1[k - 1] == 'A' && t1 + 1 <= l1)
              s1[k] = 'C', t1++;
            else if (t1 + 1 <= l1 && k + 1 == n - 1 && s1[k + 1] == 'C')
              s1[k] = 'A', t1++;
            else if (k + 1 == n - 1 && s1[k + 1] == 'C')
              s1[k] = 'D';
            else {
              s1[k] = 'A';
              if (k + 1 == n - 1 && s1[k + 1] == 'C') t1++;
            }
          }
          if (m == 2 && s2[0] == 'A' && s2[1] == 'C') t2++;
          for (int k = 1; k < m - 1; k++) {
            if (s2[k - 1] == 'A' && t2 + 1 <= l2)
              s2[k] = 'C', t2++;
            else if (t2 + 1 <= l2 && k + 1 == m - 1 && s2[k + 1] == 'C')
              s2[k] = 'A', t2++;
            else if (k + 1 == m - 1 && s2[k + 1] == 'C')
              s2[k] = 'D';
            else
              s2[k] = 'A';
          }
          if (check(t1, t2)) {
            cout << s1 << endl;
            cout << s2 << endl;
            return 0;
          }
        }
    }
  }
  cout << "Happy new year!" << endl;
  return 0;
}
