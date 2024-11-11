#include <bits/stdc++.h>
using namespace std;
char sol[1000100], s[1000100], t[1000100];
int lit[1000100], n, m, K;
void back(int k, int eq) {
  if (k > m || k > n) {
    if (eq && n <= m) return;
    for (int i = 'a'; i <= 'z'; ++i) {
      for (int j = 1; j <= lit[i]; ++j) sol[k++] = i;
    }
    K = 1;
    return;
  }
  if (eq) {
    if (lit[t[k]]) {
      sol[k] = t[k];
      --lit[t[k]];
      back(k + 1, eq);
      if (K) return;
      ++lit[t[k]];
      for (int i = t[k] + 1; i <= 'z'; ++i)
        if (lit[i]) {
          lit[i]--;
          sol[k] = i;
          back(k + 1, !eq);
          if (K) return;
          ++lit[i];
          return;
        }
    } else {
      for (int i = t[k] + 1; i <= 'z'; ++i)
        if (lit[i]) {
          lit[i]--;
          sol[k] = i;
          back(k + 1, !eq);
          if (K) return;
          ++lit[i];
          return;
        }
    }
  } else {
    for (int i = 'a'; i <= 'z'; ++i)
      if (lit[i]) {
        lit[i]--;
        sol[k] = i;
        back(k + 1, eq);
        if (K) return;
        ++lit[i];
        return;
      }
  }
}
int main() {
  cin >> (s + 1) >> (t + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) lit[s[i]]++;
  m = strlen(t + 1);
  back(1, 1);
  if (K)
    cout << (sol + 1);
  else
    cout << "-1";
  return 0;
}
