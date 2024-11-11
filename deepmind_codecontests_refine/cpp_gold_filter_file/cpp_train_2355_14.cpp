#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d", &n);
  scanf("%d", &x);
  if (x == 0 && n == 2) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if (n == 1) {
    printf("%d\n", x);
    return 0;
  }
  if (n == 2) {
    printf("%d %d\n", x | (1 << 17), (1 << 17));
    return 0;
  }
  set<int> ans;
  int val = 0;
  int i = 1;
  while (i <= n - 3) {
    val ^= i;
    ans.insert(i);
    i++;
  }
  ans.insert((1 << 18) | (1 << 17) | (val ^ x));
  ans.insert(1 << 18);
  ans.insert(1 << 17);
  set<int>::iterator it = ans.begin();
  int check = 0;
  while (it != ans.end()) {
    printf("%d ", *it);
    check ^= *it;
    it++;
  }
  printf("\n");
  assert((check ^ x) == 0);
  return 0;
}
