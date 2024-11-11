#include <bits/stdc++.h>
using namespace std;
const int MAXX = 1e7 + 10;
vector<int> ans;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int num = 1;
  printf("%d\n", k * (6 * n - 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", num * k);
      if (j == 2)
        num += 2;
      else
        num++;
    }
    num++;
    puts("");
  }
  return 0;
}
