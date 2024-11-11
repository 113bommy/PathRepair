#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const double PI = acos(-1);
const long long INFF = (long long)1e18;
const int INF = (int)1e9;
const int mod = (int)1e9 + 9;
const int MAX = (int)1e5 + 7;
int a[MAX], T[MAX], first[MAX], typ[MAX];
vector<int> st[MAX];
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  ;
  for (int i = (1); i < (n + 1); ++i) scanf("%d", a + i);
  if (m == 0) {
    for (int i = (1); i < (n + 1); ++i) puts("Lie");
    return 0;
  } else if (m == n) {
    for (int i = (1); i < (n + 1); ++i) puts("Truth");
    return 0;
  }
  for (int i = (1); i < (n + 1); ++i) {
    if (a[i] > 0)
      T[a[i]]++;
    else {
      first[-a[i]]++;
      st[-a[i]].push_back(i);
    }
  }
  int sum = 0, tt = 0, p;
  for (int i = (1); i < (n + 1); ++i) sum += T[i];
  for (int i = (1); i < (n + 1); ++i) {
    int f = first[i] + sum - T[i];
    if (f == n - m) {
      tt++;
      p = i;
    } else if (f > n - m) {
      for (int j : st[i]) {
        typ[j] = 1;
      }
    }
  }
  if (tt == 1) {
    for (int i = (1); i < (n + 1); ++i) {
      if (a[i] > 0) {
        if (a[i] == p)
          typ[i] = 1;
        else
          typ[i] = -1;
      } else {
        if (a[i] != -p)
          typ[i] = 1;
        else
          typ[i] = -1;
      }
    }
  }
  int sum2 = n - sum;
  for (int i = (1); i < (n + 1); ++i) {
    int v1, v2;
    if (a[i] > 0) {
      v1 = sum - T[a[i]] + first[a[i]];
      v2 = first[a[i]];
      if (v1 != n - m) {
        typ[i] = -1;
      }
      if (v2 > m) {
        typ[i] = 1;
      }
    } else {
      v1 = T[-a[i]];
      v2 = T[-a[i]] + sum2 - first[-a[i]];
      if (v1 > n - m) {
        typ[i] = -1;
      }
      if (v2 != m) {
        typ[i] = 1;
      }
    }
  }
  int t1 = 0, t2 = 0;
  for (int i = (1); i < (n + 1); ++i) {
    if (typ[i] == -1)
      t1++;
    else if (typ[i] == 1)
      t2++;
  }
  if (t1 == n - m) {
    for (int i = (1); i < (n + 1); ++i)
      if (typ[i] != -1) typ[i] = 1;
  } else if (t2 == m) {
    for (int i = (1); i < (n + 1); ++i)
      if (typ[i] != 1) typ[i] = -1;
  }
  for (int i = (1); i < (n + 1); ++i) {
    if (typ[i] == 1)
      puts("Truth");
    else if (typ[i] == 0)
      puts("Not defined");
    else
      puts("Lie");
  }
  return 0;
}
