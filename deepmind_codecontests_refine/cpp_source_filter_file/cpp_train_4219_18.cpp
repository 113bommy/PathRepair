#include <bits/stdc++.h>
int n, s, a, s_a = 0;
std::priority_queue<int> q;
int main() {
  scanf("%d %d", &n, &s);
  while (n--) {
    scanf("%d", &a);
    q.push(a);
  }
  n = 0;
  while (s >= s_a) {
    s_a += q.top();
    q.pop();
    ++n;
  }
  printf("%d", n);
  return 0;
}
