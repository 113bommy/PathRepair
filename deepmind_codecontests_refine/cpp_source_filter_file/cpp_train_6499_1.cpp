#include <bits/stdc++.h>
using namespace std;
const int max_n = 1000 + 10;
bool a[max_n][max_n];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int t;
      scanf("%d", &t);
      if (t == '1') a[i][j] = true;
    }
  int cur = 0;
  for (int i = 0; i < n; i++)
    if (a[i][i] == true) cur++;
  cur %= 2;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 3)
      printf("%d", cur);
    else {
      int k;
      scanf("%d", &k);
      cur++;
      cur %= 2;
    }
  }
}
