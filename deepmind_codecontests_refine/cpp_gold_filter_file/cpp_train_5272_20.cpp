#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
int n, m;
vector<int> v[maxn], ans[maxn];
queue<int> chet, nechet;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 1) {
    printf("YES\n");
    printf("1");
    return 0;
  }
  if ((n == 1 && m == 2) || (n == 2 && m == 1)) {
    printf("NO\n");
    return 0;
  }
  if ((n == 1 && m == 3) || (n == 3 && m == 1)) {
    printf("NO\n");
    return 0;
  }
  if (n == 1 && m >= 4) {
    printf("YES\n");
    if (m & 1) {
      for (int i = 2; i < m; i += 2) {
        printf("%d ", i);
      }
      for (int i = 1; i <= m; i += 2) {
        printf("%d ", i);
      }
    } else {
      for (int i = 2; i <= m; i += 2) {
        printf("%d ", i);
      }
      for (int i = 1; i < m; i += 2) {
        printf("%d ", i);
      }
    }
    return 0;
  }
  if (m == 1 && n >= 4) {
    printf("YES\n");
    if (n & 1) {
      for (int i = 2; i < n; i += 2) {
        printf("%d\n", i);
      }
      for (int i = 1; i <= n; i += 2) {
        printf("%d\n", i);
      }
    } else {
      for (int i = 2; i <= n; i += 2) {
        printf("%d\n", i);
      }
      for (int i = 1; i < n; i += 2) {
        printf("%d\n", i);
      }
    }
    return 0;
  }
  if ((n == 2 && m == 1) || n == 1 && m == 2) {
    printf("NO");
    return 0;
  }
  if ((n == 2 && m == 2)) {
    printf("NO");
    return 0;
  }
  if (n == 2 && m == 3) {
    printf("NO\n");
    return 0;
  }
  if (n == 3 && m == 2) {
    printf("NO\n");
    return 0;
  }
  if (n == 3 && m == 3) {
    printf("YES\n");
    printf("6 1 8\n");
    printf("7 5 3\n");
    printf("2 9 4\n");
    return 0;
  }
  if (n == 2 && m == 4) {
    printf("YES\n");
    printf("5 4 7 2\n");
    printf("3 6 1 8\n");
    return 0;
  } else {
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        v[i].push_back((i - 1) * m + j);
        if (((i & 1) && (j & 1)) || (!(i & 1) && !(j & 1)))
          chet.push((i - 1) * m + j);
        else
          nechet.push((i - 1) * m + j);
      }
    }
    if (n < m) {
      for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
          if (chet.size() > 0) {
            int q = chet.front();
            ans[i].push_back(q);
            chet.pop();
          } else {
            int q = nechet.front();
            ans[i].push_back(q);
            nechet.pop();
          }
        }
      }
    } else {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (chet.size() > 0) {
            int q = chet.front();
            ans[i].push_back(q);
            chet.pop();
          } else {
            int q = nechet.front();
            ans[i].push_back(q);
            nechet.pop();
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        printf("%d ", ans[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
