#include <bits/stdc++.h>
using namespace std;
const int M = 1000 * 100 + 5;
int n, m, s;
int a[M], b[M], c[M], answer[M];
pair<int, pair<int, int> > d[M];
vector<int> ans[M];
int check(int X) {
  int i, j, t, cost = 0;
  t = m - 1;
  i = n - 1;
  priority_queue<pair<int, int> > q;
  while (t >= 0) {
    while (d[i].first >= a[t] && i >= 0) {
      q.push(make_pair(-d[i].second.first, -d[i].second.second));
      i--;
    }
    if (q.empty()) return 0;
    int head = -q.top().first;
    cost += head;
    ans[X].push_back(-q.top().second);
    q.pop();
    t -= X;
  }
  return (cost <= s);
}
pair<int, int> A[M];
int id[M];
int main() {
  ios::sync_with_stdio(false);
  int i, j, ch = 0;
  cin >> n >> m >> s;
  for (i = 0; i < m; i++) {
    cin >> a[i];
    A[i] = make_pair(a[i], i);
  }
  sort(A, A + m);
  for (i = 0; i < m; i++) id[A[i].second] = i;
  sort(a, a + m);
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++) cin >> c[i];
  for (i = 0; i < n; i++) d[i] = make_pair(b[i], make_pair(c[i], i + 1));
  sort(d, d + n);
  int hi, lo, mid, flag;
  lo = 1;
  hi = m + 1;
  while (lo < hi) {
    mid = (hi + lo) / 2;
    flag = check(mid);
    if (flag) {
      hi = mid;
      ch = 1;
    } else
      lo = mid + 1;
  }
  if (ch == 0) {
    cout << "NO";
    cin >> i;
    return 0;
  } else
    cout << "YES" << endl;
  int minX = mid + 1 - flag;
  i = m - 1;
  int l = 0;
  while (i >= 0) {
    for (j = 0; j < minX; j++) {
      if (i < 0) break;
      answer[i--] = ans[minX][l];
    }
    l++;
  }
  for (i = 0; i < m; i++) cout << answer[id[i]] << " ";
  cin >> i;
}
