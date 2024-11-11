#include <bits/stdc++.h>
using namespace std;
int find_first_one(int x) {
  int res = 0;
  int y = x;
  if (y == 0) return -1;
  while (y > 0) {
    if (y % 2 == 1) return res;
    y >>= 1;
    res++;
  }
  return -1;
}
int main() {
  int x;
  scanf("%d", &x);
  int t = x;
  vector<int> p;
  int n;
  int flag = 0;
  if (x == 1) {
    printf("1\n");
    return 0;
  }
  if (x == (1 << find_first_one(x))) {
    printf("%d\n", 1);
    printf("%d\n", find_first_one(x));
    return 0;
  }
  if ((x + 1) == (1 << find_first_one(x + 1))) {
    printf("%d\n", 0);
    return 0;
  }
  while (x != (1 << find_first_one(x))) {
    n = find_first_one(x);
    x ^= (1 << n) - 1;
    p.push_back(n);
    x++;
  }
  if (!p.size())
    printf("0\n");
  else
    printf("%d\n", (int)p.size() * 2 - 1);
  for (int i = 0; i < p.size(); i++) printf("%d ", p[i]);
  if ((int)p.size() != 0) printf("\n");
  return 0;
}
