#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long n, p;
pair<int, int> a[maxn];
int tr[maxn << 2];
long long ans[maxn];
queue<long long> q;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second < b.second;
}
void pushup(int num) { tr[num] = min(tr[num << 1], tr[num << 1 | 1]); }
void build(int l, int r, int num) {
  tr[num] = n + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, num << 1);
  build(mid + 1, r, num << 1 | 1);
  pushup(num);
}
void modify(int l, int r, int num, int pos, int tmp) {
  if (l == r) {
    tr[num] = tmp;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    modify(l, mid, num << 1, pos, tmp);
  else
    modify(mid + 1, r, num << 1 | 1, pos, tmp);
  pushup(num);
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n, cmp);
  int now = 0;
  int lst = n + 1;
  long long times = 0;
  int sum = 0;
  build(1, n, 1);
  while (true) {
    if (sum == n) break;
    if (!q.empty())
      times = q.front(), q.pop();
    else if (tr[1] != n + 1) {
      int d = tr[1];
      ans[d] = (times += p);
      lst = d;
      sum++;
      modify(1, n, 1, d, n + 1);
    } else {
      int d = a[now].second;
      ans[d] = (times = a[now].first + p);
      lst = d;
      sum++;
      now++;
    }
    while (now < n && times >= a[now].first) {
      int d = a[now].second;
      if (a[now].second < lst) {
        long long k = (q.size() + 1) * p + times;
        q.push((ans[d] = k));
        sum++;
        lst = d;
      } else {
        modify(1, n, 1, d, d);
      }
      now++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
    if (i == n)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
