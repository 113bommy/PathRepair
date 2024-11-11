#include <bits/stdc++.h>
using namespace std;
int n, i, timer, x, res[100005];
stack<int> v;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= (n << 1); i++) {
    char ch;
    cin >> ch;
    if (ch == '+')
      v.push(timer++);
    else {
      if (v.empty()) return puts("NO"), 0;
      scanf("%d", &x);
      if (x < res[v.top() + 1]) return puts("NO"), 0;
      res[v.top()] = x;
      v.pop();
    }
  }
  puts("YES");
  for (i = 1; i <= n; i++) printf("%d ", res[i]);
}
