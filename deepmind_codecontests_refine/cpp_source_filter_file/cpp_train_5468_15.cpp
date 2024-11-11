#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
stack<int> s;
int n, m, k = 0, a[maxn], b[maxn], t[maxn], r[maxn], ans[maxn];
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &t[i], &r[i]);
    while (!s.empty() && r[s.top()] < r[i]) s.pop();
    s.push(i);
  }
  while (!s.empty()) {
    ans[++k] = s.top();
    s.pop();
  }
  int left = 1, right = r[ans[k]];
  sort(b + 1, b + 1 + r[ans[k]]);
  for (int i = k - 1; i >= 0; --i) {
    for (int j = r[ans[i + 1]]; j > r[ans[i]]; --j)
      if (t[ans[i + 1]] == 1)
        a[j] = b[right--];
      else
        a[j] = b[left++];
  }
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
}
