#include <bits/stdc++.h>
using namespace std;
const int M = 101;
int cnt[M];
int main() {
  int n, m, a;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    int temp;
    for (int j = 0; j < a; ++j) {
      scanf("%d", &temp);
      cnt[temp]++;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (cnt[i] == 0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
