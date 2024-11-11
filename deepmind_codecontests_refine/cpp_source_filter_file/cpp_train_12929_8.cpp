#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int f, a[N], id[N], n;
vector<int> ans[N];
int main() {
  cin >> f;
  for (int i = 1; i <= f; i++) a[i] = gi(), id[i] = i;
  sort(id + 1, id + f + 1, [&](int x, int y) { return a[x] > a[y]; });
  deque<int> q;
  for (int i = 1; i <= a[id[1]]; i++) ans[id[1]].push_back(++n), q.push_back(n);
  id[f + 1] = f + 1;
  a[f + 1] = 3;
  for (int i = 2; i <= f; i++) {
    int cur = q.size(), tmp = 0, x = id[i];
    for (int j = 1; j < a[x]; j++)
      if (cur - j + a[x] - j >= a[id[i + 1]]) tmp = j;
    for (int j = 1; j < tmp; j++) ans[x].push_back(q.back()), q.pop_back();
    ans[x].push_back(q.back());
    for (int j = 1; j < a[x] - tmp; j++) q.push_back(++n), ans[x].push_back(n);
    ans[x].push_back(q.front());
    q.push_front(q.back());
    q.pop_back();
  }
  cout << n << '\n';
  for (int i = 1; i <= n; i++, cout << '\n')
    for (auto x : ans[i]) cout << x << ' ';
  return 0;
}
