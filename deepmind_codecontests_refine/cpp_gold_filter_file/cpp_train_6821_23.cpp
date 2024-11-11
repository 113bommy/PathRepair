#include <bits/stdc++.h>
using namespace std;
pair<int, int> row[5005], col[5005];
int main() {
  int n = ({
    register int x;
    scanf("%d", &x);
    x;
  }),
      m = ({
        register int x;
        scanf("%d", &x);
        x;
      }),
      k = ({
        register int x;
        scanf("%d", &x);
        x;
      });
  for (int i = 1; i <= k; i++) {
    int x = ({
      register int x;
      scanf("%d", &x);
      x;
    }),
        y = ({
          register int x;
          scanf("%d", &x);
          x;
        }),
        z = ({
          register int x;
          scanf("%d", &x);
          x;
        });
    if (x == 1) row[y] = make_pair(i, z);
    if (x == 2) col[y] = make_pair(i, z);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (row[i].first == 0)
        printf("%d ", col[j].second);
      else if (col[j].first == 0)
        printf("%d ", row[i].second);
      else if (row[i].first > col[j].first)
        printf("%d ", row[i].second);
      else if (row[i].first < col[j].first)
        printf("%d ", col[j].second);
    }
    puts("");
  }
}
