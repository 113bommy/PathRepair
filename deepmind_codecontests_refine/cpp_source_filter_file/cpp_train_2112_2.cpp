#include <bits/stdc++.h>
using namespace std;
int n, x[100001], num[100001], m, m2, ans[100001], num2[100001];
char c[100001];
bool flag;
map<int, int> f;
int main() {
  flag = true;
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    cin >> c[i];
    if (c[i] == '+')
      continue;
    else
      scanf("%d", &x[i]);
  }
  stack<int> s;
  for (int i = 2 * n; i >= 1; i--) {
    if (c[i] == '+') {
      if (s.empty()) {
        flag = false;
        break;
      } else {
        ans[++m] = s.top();
        s.pop();
      }
    } else {
      if (!s.empty() && x[i] > s.top()) {
        flag = false;
        break;
      } else
        s.push(x[i]);
    }
  }
  if (!flag) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for (int i = n; i >= 1; i--) printf("%d ", ans[i]);
  return 0;
}
