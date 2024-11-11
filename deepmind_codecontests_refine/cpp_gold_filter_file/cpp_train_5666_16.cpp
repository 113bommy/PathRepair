#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100005];
struct t {
  int no, b, c;
} stu[100005];
inline bool cmp(t a, t b) { return a.c > b.c; }
bool cmp1(t a, t b) { return a.b < b.b; }
bool operator<(t a, t b) { return a.c > b.c; }
priority_queue<t, vector<t> > h;
int m, n, s;
int ans[100005];
int tmpans[100005];
bool check(int x);
int main() {
  cin >> n >> m >> s;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for (int i = 1; i <= n; ++i) stu[i].no = i;
  for (int i = 1; i <= n; ++i) scanf("%d", &stu[i].b);
  for (int i = 1; i <= n; ++i) scanf("%d", &stu[i].c);
  sort(a + 1, a + m + 1);
  sort(stu + 1, stu + n + 1, cmp1);
  int l = 1, r = m;
  if (check(m) == false)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
  }
  return 0;
}
bool check(int x) {
  int pa = m;
  int pb = n;
  int rem = s;
  while (!h.empty()) h.pop();
  while (pa >= 0) {
    int sat = a[pa].first;
    for (; stu[pb].b >= sat; --pb) h.push(stu[pb]);
    if (h.empty()) return false;
    t NextStu = h.top();
    h.pop();
    if (NextStu.c > rem) return false;
    for (int i = 0; i < x; ++i) {
      tmpans[a[pa].second] = NextStu.no;
      --pa;
      if (pa < 0) break;
    }
    rem -= NextStu.c;
  }
  for (int i = 1; i <= m; ++i) ans[i] = tmpans[i];
  return true;
}
