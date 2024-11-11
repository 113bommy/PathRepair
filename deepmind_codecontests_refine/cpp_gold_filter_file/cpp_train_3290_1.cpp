#include <bits/stdc++.h>
using namespace std;
int S[300][300] = {0};
bool pres[205] = {0};
bool same(int a, int b) {
  if (S[a][0] != S[b][0]) return false;
  for (int i = 1; i <= S[a][0]; ++i)
    if (S[a][i] != S[b][i]) return false;
  return true;
}
int main() {
  int n;
  int k;
  int a;
  int m;
  scanf("%d", &n);
  m = (n * (n - 1)) / 2;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &a);
      S[a][++S[a][0]] = i;
      pres[a] = true;
    }
  }
  for (int i = 1; i <= 200; ++i)
    if (pres[i]) {
      sort(S[i] + 1, S[i] + S[i][0] + 1);
    }
  int sol[205][205];
  bool taken[205] = {0};
  int nsol = 0;
  for (int i = 1; i <= 200; ++i) {
    if (pres[i] && !taken[i]) {
      sol[nsol][0] = 1;
      sol[nsol][1] = i;
      for (int j = i + 1; j <= 200; ++j) {
        if (pres[j] && !taken[j]) {
          if (same(i, j)) {
            sol[nsol][++sol[nsol][0]] = j;
          }
        }
      }
      for (int j = 1; j <= sol[nsol][0]; ++j) taken[sol[nsol][j]] = true;
      nsol++;
    }
  }
  if (nsol == 1) {
    vector<int> v;
    bool first = true;
    for (int i = 1; i <= 200; ++i)
      if (pres[i]) {
        if (first) {
          printf("1 %d\n", i);
          first = false;
        } else {
          v.push_back(i);
        }
      }
    printf("%d", v.size());
    for (int i = 0; i < v.size(); ++i) printf(" %d", v[i]);
    putchar('\n');
  } else {
    for (int i = 0; i < nsol; ++i) {
      printf("%d", sol[i][0]);
      for (int j = 1; j <= sol[i][0]; ++j) {
        printf(" %d", sol[i][j]);
      }
      putchar('\n');
    }
  }
  return 0;
}
