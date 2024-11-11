#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 1;
const int INF = (int)1e9 + 7;
int n, a[N], b[N], posa[N], posb[N], ans[N], toRight[N], toLeft[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    posa[a[i] - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    posb[b[i] - 1] = i;
  }
  for (int i = 0; i < n; i++) ans[i] = INF;
  memset(toRight, -1, sizeof(toRight));
  memset(toLeft, 127, sizeof(toLeft));
  for (int i = 0; i < n; i++)
    if (posa[i] <= posb[i]) {
      int val = posb[i] - posa[i];
      ans[val] = 0;
      toRight[val] = max(toRight[val], val + posa[i]);
      toLeft[val] = min(toLeft[val], val - (n - posa[i] - 1));
    } else {
      int val = posb[i] + n - posa[i];
      ans[val] = 0;
      toRight[val] = max(toRight[val], val + posa[i]);
      toLeft[val] = min(toLeft[val], val - (n - posa[i] - 1));
    }
  vector<int> pos, bound;
  for (int i = 0; i < 2 * n; i++) {
    int cur = i % n;
    if (i < n && ans[i] == 0) pos.push_back(i), bound.push_back(toRight[i]);
    while ((int)(pos).size() && bound.back() < i)
      pos.pop_back(), bound.pop_back();
    if ((int)(pos).size()) {
      ans[cur] = min(ans[cur], i - pos.back());
    }
  }
  pos.clear(), bound.clear();
  for (int i = n - 1; i >= -n; i--) {
    int cur = i >= 0 ? i : i + n;
    if (i >= 0 && ans[i] == 0) {
      pos.push_back(i);
      bound.push_back(toLeft[i]);
    }
    while ((int)(pos).size() && bound.back() > i)
      pos.pop_back(), bound.pop_back();
    if ((int)(pos).size()) {
      ans[cur] = min(ans[cur], pos.back() - i);
    }
  }
  for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}
