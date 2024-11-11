#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX = 200200;
pii arr[MAX];
int d, n, m, nxt[MAX];
long long solve(int idx, int curOil) {
  if (curOil < 0) return -(1LL << 55);
  if (idx == n) return 0;
  int dis = arr[nxt[idx]].first - arr[idx].first;
  if (dis < m)
    return 1LL * arr[idx].second * max(0, dis - curOil) +
           solve(nxt[idx], max(0, curOil - dis));
  return 1LL * arr[idx].second * (m - curOil) +
         solve(idx + 1, m - (arr[idx + 1].first - arr[idx].first));
}
int main() {
  scanf("%d%d%d", &d, &m, &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
  sort(arr, arr + n);
  stack<int> s;
  arr[n].first = d;
  for (int i = 0; i <= n; i++) {
    while (s.size() && arr[s.top()].second > arr[i].second)
      nxt[s.top()] = i, s.pop();
    s.push(i);
  }
  printf("%I64d\n", max(-1LL, solve(0, m - arr[0].first)));
  return 0;
}
