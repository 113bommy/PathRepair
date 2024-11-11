#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
  return p1.first < p2.first;
}
int k, m;
int curr;
int flag = 0;
set<int> out;
void sol(int a, int b) {
  if (!b) {
    int x, t;
    t = abs(a);
    x = abs(t - k);
    if (x >= 10000) return;
    if (out.size() < m) out.insert((10000 * x) + curr);
    if (out.size() < m) out.insert((10000 * curr) + x);
    if (out.size() == m) {
      flag = 1;
    }
    return;
  }
  sol(a - b % 10, b / 10);
  sol(a + b / 10, b / 10);
  sol(a * (b % 10), b / 10);
}
int main() {
  scanf("%d", &k);
  scanf("%d", &m);
  int i = 0;
  while (1) {
    curr = i;
    sol(i % 10, i / 10);
    if (flag)
      break;
    else
      i++;
  }
  for (typeof((out).begin()) it = (out).begin(); it != (out).end(); it++) {
    printf("%08d\n", *it);
  }
  return 0;
}
