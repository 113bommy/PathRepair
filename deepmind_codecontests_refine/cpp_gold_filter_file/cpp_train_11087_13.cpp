#include <bits/stdc++.h>
using namespace std;
int a[100005];
stack<int> s;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  int maxx = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (maxx >= a[i])
      s.push(maxx + 1 - a[i]);
    else
      s.push(0);
    maxx = max(maxx, a[i]);
  }
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  puts("");
  return 0;
}
