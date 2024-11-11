#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000005;
const int mm = 200005;
const int root = 1;
const int seed = 131;
int n, m;
unsigned long long s1[mm], s2[mm], fac[mm];
char st1[mm], st2[mm];
int ss1[mm][27], ss2[mm][27];
int check(int l1, int r1, int l2, int r2) {
  for (int i = 'a'; i <= 'z'; i++)
    if (ss1[r1][i - 'a'] - ss1[l1 - 1][i - 'a'] !=
        ss2[r2][i - 'a'] - ss2[l2 - 1][i - 'a'])
      return 0;
  return 1;
}
int dfs(int l1, int r1, int l2, int r2) {
  int l = r1 - l1 + 1;
  if (s1[r1] - s1[l1 - 1] * fac[l] == s2[r2] - s2[l2 - 1] * fac[l]) return 1;
  if (l & 1) return 0;
  int m1 = (l1 + r1) >> 1;
  int m2 = (l2 + r2) >> 1;
  if (check(l1, m1, m2 + 1, r2) && check(m1 + 1, r1, l2, m2) &&
      dfs(l1, m1, m2 + 1, r2) && dfs(m1 + 1, r1, l2, m2))
    return 1;
  if (check(l1, m1, l2, m2) && check(m1 + 1, r1, m2 + 1, r2) &&
      dfs(l1, m1, l2, m2) && dfs(m1 + 1, r1, m2 + 1, r2))
    return 1;
  return 0;
}
int main() {
  scanf("%s%s", st1, st2);
  int l1 = strlen(st1);
  fac[0] = 1;
  for (int i = 1; i <= l1; i++) {
    s1[i] = s1[i - 1] * seed + st1[i - 1];
    s2[i] = s2[i - 1] * seed + st2[i - 1];
    fac[i] = fac[i - 1] * seed;
    for (int j = 'a'; j <= 'z'; j++) {
      ss1[i][j - 'a'] = ss1[i - 1][j - 'a'];
      ss2[i][j - 'a'] = ss2[i - 1][j - 'a'];
      if (j == st1[i - 1]) ss1[i][j - 'a']++;
      if (j == st2[i - 1]) ss2[i][j - 'a']++;
    }
  }
  if (dfs(1, l1, 1, l1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
