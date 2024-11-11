#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100011;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
struct bug {
  int val, idx;
} b[MAX_N];
struct student {
  int ability, passNum, idx;
} s[MAX_N];
bool cmp(const bug &a, const bug &b) { return a.val > b.val; }
bool cmp1(const student &a, const student &b) { return a.ability > b.ability; }
int n, m, S;
int task[MAX_N];
void init() {
  scanf("%d%d%d", &n, &m, &S);
  for (int i = 0; i < m; i++) scanf("%d", &b[i].val);
  for (int i = 0; i < m; i++) b[i].idx = i;
  sort(b, b + m, cmp);
  for (int i = 0; i < n; i++) scanf("%d", &s[i].ability);
  for (int i = 0; i < n; i++) scanf("%d", &s[i].passNum);
  for (int i = 0; i < n; i++) s[i].idx = i + 1;
  sort(s, s + n, cmp1);
}
bool check(int day) {
  int idx = 0, maxSize = (m - 1) / day + 1, sum = 0;
  set<pair<int, int> > q;
  for (int i = 0; i < m; i += day) {
    while (idx < n && s[idx].ability >= b[i].val) {
      if (q.size() < maxSize) {
        q.insert(make_pair(s[idx].passNum, idx));
      } else {
        pair<int, int> temp = *(--q.end());
        if (s[idx].passNum < temp.first) {
          q.erase(--q.end());
          q.insert(make_pair(s[idx].passNum, idx));
        }
      }
      idx++;
    }
    if (q.empty()) return false;
    pair<int, int> stu = *(q.begin());
    q.erase(q.begin());
    int stuidx = s[stu.second].idx;
    for (int j = i; j < i + day && j < m; j++) task[b[j].idx] = stuidx;
    sum += stu.first;
    if (sum > S) return false;
  }
  return true;
}
void solve() {
  int le = 1, ri = m, res = -1;
  while (le < ri) {
    int mid = (le + ri) / 2;
    if (check(mid)) {
      res = mid;
      ri = mid - 1;
    } else {
      le = mid + 1;
    }
  }
  if (res == -1) {
    puts("NO");
  } else {
    check(res);
    puts("YES");
    for (int i = 0; i < m; i++) {
      printf("%d ", task[i]);
    }
    puts("");
  }
}
int main() {
  init();
  solve();
  return 0;
}
