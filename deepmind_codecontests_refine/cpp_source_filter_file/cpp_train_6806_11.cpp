#include <bits/stdc++.h>
using namespace std;
int a[100000 + 5];
stack<int> s;
int main() {
  int n;
  scanf("%d", &n);
  int ans = -1;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    while (s.empty() != true && s.top() < a[i]) {
      ans = max(ans, s.top() | a[i]);
      s.pop();
    }
    s.push(a[i]);
  }
  while (s.empty() != true) s.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (s.empty() != true && s.top() < a[i]) {
      ans = max(ans, s.top() | a[i]);
      s.pop();
    }
    s.push(a[i]);
  }
  printf("%d\n", ans);
  return 0;
}
