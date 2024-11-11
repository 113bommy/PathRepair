#include <bits/stdc++.h>
using namespace std;
struct ST {
  long long x, y, id;
  bool operator<(const ST &p) const { return x < p.x || (x == p.x && y < p.y); }
} st[100005];
struct ST2 {
  long long x, y, id;
  bool operator<(const ST2 &p) const {
    return x > p.x || (x == p.x && y > p.y);
  }
} st2[100005];
pair<long long, long long> pr[200055];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    st[i].x = x, st[i].y = y, st[i].id = i;
    st2[i].x = x, st2[i].y = y, st2[i].id = i;
    pr[i] = pr[n + i] = {x, y};
  }
  if (n % 2 == 1) cout << "NO\n", exit(0);
  sort(st + 1, st + 1 + n);
  sort(st2 + 1, st2 + 1 + n);
  int id1 = st[1].id;
  int id2 = st2[1].id;
  int fg = 0;
  for (int i = id1, j = id2; i < id1 + n / 2; i++, j++) {
    long long p1 = pr[i].first - pr[i + 1].first;
    long long p2 = pr[j].first - pr[j + 1].first;
    long long q1 = pr[i].second - pr[i + 1].second;
    long long q2 = pr[j].second - pr[j + 1].second;
    if (p1 != -p2 || q1 != -q2) {
      fg = 1;
      break;
    }
  }
  if (fg)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
