#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
int n, m, Ans[100100], a[100100], b[100100], c[100100], s;
vector<pair<int, int> > stud, bug;
bool check(int time) {
  int cnt[100100];
  for (int i = 0; i < n; i++) cnt[i] = 0;
  set<pair<int, int> > q;
  q.clear();
  int ans[100100];
  int cur = n - 1, cost = 0;
  for (int i = m - 1; i >= 0; i -= time) {
    while (cur >= 0 && stud[cur].first >= bug[i].first) {
      int pos = stud[cur].second;
      if (c[pos] + cost <= s) q.insert(make_pair(c[pos], pos));
      cur--;
    }
    if (q.empty()) return false;
    int j = bug[i].second;
    ans[j] = q.begin()->second;
    cost += q.begin()->first;
    if (cost > s) return false;
    q.erase(q.begin());
    for (int k = i - 1; k >= max(0, i - time + 1); k--) {
      ans[bug[k].second] = ans[j];
    }
  }
  for (int i = 0; i < m; i++) Ans[i] = ans[i];
  return true;
}
int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    bug.push_back(make_pair(a[i], i));
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    stud.push_back(make_pair(b[i], i));
  }
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(bug.begin(), bug.end());
  sort(stud.begin(), stud.end());
  int j;
  for (j = n - 1; j >= 0; j--) {
    if (c[stud[j].second] <= s) break;
  }
  if (stud[j].first < bug[m - 1].first) {
    cout << "NO";
    return 0;
  } else {
    cout << "YES" << endl;
    int l = 1, r = oo;
    while (l < r) {
      int mid = (l + r) / 2;
      if (!check(mid))
        l = mid + 1;
      else
        r = mid;
    }
    for (int i = 0; i < m; i++) cout << Ans[i] + 1 << " ";
  }
}
