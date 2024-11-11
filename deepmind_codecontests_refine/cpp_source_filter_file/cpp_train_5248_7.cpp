#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;
int arr[maxn];
int ans[maxn];
stack<int> s;
int main() {
  int n;
  scanf("%d", &n);
  memset(ans, 0, sizeof ans);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  for (int i = n; i >= 1; --i) {
    if (s.empty()) {
      s.push(i);
      ans[i] = 0;
      continue;
    }
    if (arr[s.top()] > arr[i]) {
      ans[i] = 0;
      s.push(i);
    } else {
      ans[i] = max(1, ans[s.top()]);
      s.pop();
      while (s.size() && arr[i] > arr[s.top()]) {
        ans[i] = max(ans[i], ans[s.top()] + 1);
        s.pop();
      }
      s.push(i);
    }
  }
  int val = 0;
  for (int i = 1; i <= n; ++i) {
    val = max(val, ans[i]);
  }
  printf("%d\n", val);
  return 0;
}
