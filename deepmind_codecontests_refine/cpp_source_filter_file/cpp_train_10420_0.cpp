#include <bits/stdc++.h>
using namespace std;
const int N = 51;
const int mod = 1e9 + 7;
int n, x;
set<int> ft1, ft2;
int find(int t) {
  int ret = -1;
  if (ft1.find(t) != ft1.end()) {
    ret = 0;
  } else if (ft2.find(t) != ft2.end()) {
    ret = 1;
  }
  return -1;
}
int checkm(int a, int b) {
  if (a == -1)
    a = b;
  else {
    if (b != -1) a = min(a, b);
  }
  return a;
}
int main() {
  cin >> n >> x;
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    int ret1 = find(t);
    int ret2 = find(t & x);
    if (ret2 != -1) ret2 += 1;
    ans = checkm(ans, ret1);
    ans = checkm(ans, ret2);
    ft1.insert(t);
    ft2.insert(t & x);
  }
  printf("%d\n", ans);
}
