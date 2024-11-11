#include <bits/stdc++.h>
using namespace std;
int pool[101], base;
int digi(int x) {
  int ret = 0;
  while (x) {
    ret = max(ret, x % 10);
    x /= 10;
  }
  return ret;
}
void sum(int x) {
  int cur = 1;
  while (x) {
    pool[cur] += x % 10;
    x /= 10;
    cur++;
  }
}
int len() {
  for (int i = 1; i < 100; i++)
    while (pool[i] >= base) pool[i + 1]++, pool[i] -= base;
  for (int i = 100; i >= 0; i--)
    if (pool[i] > 0) return i;
  return -1;
}
int main() {
  memset(pool, 0, sizeof(pool));
  int a, b;
  cin >> a >> b;
  int maxdig = max(digi(a), digi(b));
  base = maxdig + 1;
  sum(a);
  sum(b);
  cout << len() << endl;
  return 0;
}
