#include <bits/stdc++.h>
using namespace std;
int n, k;
map<int, int> m;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k + 1; i++) {
    printf("?");
    for (int j = 1; j <= k + 1; j++)
      if (i != j) printf(" %d", j);
    puts("");
    fflush(stdout);
    int ta, tb;
    scanf("%d%d", &ta, &tb);
    m[tb]++;
  }
  printf("! %d\n", m.begin()->second);
  fflush(stdout);
}
