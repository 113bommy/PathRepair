#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > stk;
int a[100003];
int main() {
  int test = 0;
  scanf("%d", &test);
  for (int i = 0; i < test; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = test - 2; i >= 0; i--) {
    int c = 0;
    while (!stk.empty() and a[i] > stk.top().first) {
      c = max(c + 1, stk.top().second);
      stk.pop();
    }
    if (c > ans) ans = c;
    stk.push(pair<int, int>(a[i], c));
  }
  printf("%d\n", ans);
  return 0;
}
