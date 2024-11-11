#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100009], tmp[100009];
set<int> chk[11];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 1) return !printf("YES\n1");
  if (min(n, m) == 1) {
    if (max(n, m) < 4) return !printf("NO");
    puts("YES");
    if (n == 1) {
      if (max(n, m) == 4) return !printf("3 1 4 2");
      for (int i = 1; i <= n; i += 2) printf("%d ", i);
      for (int i = 2; i <= n; i += 2) printf("%d ", i);
    } else {
      if (max(n, m) == 4) return !printf("3\n1\n4\n2\n");
      for (int i = 1; i <= n; i += 2) printf("%d\n", i);
      for (int i = 2; i <= n; i += 2) printf("%d\n", i);
    }
    return 0;
  }
  if (max(n, m) < 4) {
    vector<int> stk;
    for (int i = 1; i <= n * m; i++) stk.push_back(i);
    for (int i = 1; i <= n * m; i++) {
      if (i - m >= 1) chk[i].insert(i - m);
      if (i + m <= n * m) chk[i].insert(i + m);
      if (i % m != 0) chk[i].insert(i + 1);
      if (i % m != 1) chk[i].insert(i - 1);
    }
    do {
      int i;
      for (i = 1; i <= n * m; i++) {
        int now = stk[i - 1];
        if (i - m >= 1 && chk[now].find(stk[i - m - 1]) != chk[now].end())
          break;
        if (i + m <= n * m && chk[now].find(stk[i + m - 1]) != chk[now].end())
          break;
        if (i % m != 0 && chk[now].find(stk[i + 1 - 1]) != chk[now].end())
          break;
        if (i % m != 1 && chk[now].find(stk[i - 1 - 1]) != chk[now].end())
          break;
      }
      if (i == n * m + 1) {
        puts("YES");
        for (int i = 0; i < stk.size(); i++) {
          printf("%d ", stk[i]);
          if (i % m == m - 1) puts("");
        }
        return 0;
      }
    } while (next_permutation(stk.begin(), stk.end()));
    return !printf("NO");
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[i].push_back(m * (i - 1) + j);
    }
  }
  if (n < m) {
    for (int i = 1; i <= n; i++) {
      rotate(arr[i].begin(), arr[i].begin() + 2 * i % m, arr[i].end());
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        tmp[j + 1].push_back(arr[i][j]);
      }
    }
    for (int i = 1; i <= m; i++) {
      rotate(tmp[i].begin(), tmp[i].begin() + i % n, tmp[i].end());
    }
    puts("YES");
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%d ", tmp[j][i]);
      }
      puts("");
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        tmp[j + 1].push_back(arr[i][j]);
      }
    }
    for (int i = 1; i <= m; i++) {
      rotate(tmp[i].begin(), tmp[i].begin() + 2 * i % n, tmp[i].end());
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        arr[i + 1][j - 1] = tmp[j][i];
      }
    }
    for (int i = 1; i <= n; i++) {
      rotate(arr[i].begin(), arr[i].begin() + i % m, arr[i].end());
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d ", arr[i][j]);
      }
      puts("");
    }
  }
  return 0;
}
