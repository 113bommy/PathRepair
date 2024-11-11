#include <bits/stdc++.h>
using namespace std;
int n, m, print[100001], p;
vector<pair<int, pair<int, int> > > vec;
vector<pair<int, int> > bug;
vector<int> ans, pik;
bool check(int d) {
  priority_queue<pair<int, int> > q;
  int i = 0, j;
  long long sum = 0;
  for (j = 0; j < m; j++) {
    for (; i < n; i++)
      if (vec[i].first < bug[j].first)
        break;
      else
        q.push(make_pair(vec[i].second.first * -1, vec[i].second.second));
    int ind;
    if (q.size()) {
      sum += q.top().first * -1;
      ind = q.top().second;
      q.pop();
    } else
      break;
    pik[bug[j].second] = ind;
    for (int i = 0; i < d - 1; i++) {
      j++;
      if (j >= m) break;
      pik[bug[j].second] = ind;
    }
  }
  if (sum > p || j < m) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> p;
  int a;
  for (int i = 0; i < m; i++) {
    cin >> a;
    bug.push_back(make_pair(a, i));
  }
  vec.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first;
    vec[i].second.second = i;
  }
  for (int i = 0; i < n; i++) cin >> vec[i].second.first;
  sort((bug).begin(), (bug).end());
  reverse((bug).begin(), (bug).end());
  int ind = -1;
  sort((vec).begin(), (vec).end());
  reverse((vec).begin(), (vec).end());
  int l = 1, r = m + 1;
  pik.resize(m);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = pik;
      r = mid;
    } else
      l = mid + 1;
  }
  if (ans.size()) {
    cout << "YES\n";
    for (int i = 0; i < m; i++) cout << ans[i] + 1 << ' ';
  } else
    cout << "NO\n";
  return 0;
}
