#include <bits/stdc++.h>
using namespace std;
int n, a, prepos[100005], pos[100005], divs[100005], res;
bool arith[100005];
set<int> num;
int main() {
  memset(arith, 1, sizeof arith);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    pos[a] = i;
    if (arith[a] && (divs[a] == 0 || pos[a] - prepos[a] == divs[a])) {
      num.insert(a);
      if (prepos[a] != 0) divs[a] = pos[a] - prepos[a];
      prepos[a] = pos[a];
    } else if (arith[a]) {
      arith[a] = 0;
      res--;
    }
  }
  res += num.size();
  printf("%d\n", res);
  for (set<int>::iterator it = num.begin(); it != num.end(); it++) {
    int tmp = *it;
    if (arith[tmp]) printf("%d %d\n", tmp, divs[tmp]);
  }
  return 0;
}
