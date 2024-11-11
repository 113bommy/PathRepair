#include <bits/stdc++.h>
using namespace std;
const int block = 200;
const int block2 = 350;
const int N = 100100;
int a[N];
int cnt[N];
int cc[N];
int allcnt[N];
int tmp[block2];
vector<int> large;
void update(int x, int y) {
  cc[cnt[x]]--;
  cc[cnt[x] += y]++;
}
int solve() {
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i : large)
    if (cnt[i] >= block2) q.push(cnt[i]);
  int unused = 0;
  copy(cc, cc + block2, tmp);
  int ans = 0;
  for (int i = 1; i < block2; i++) {
    if (!tmp[i]) continue;
    if (unused) {
      tmp[i]--;
      int mk = i + unused;
      unused = 0;
      ans += mk;
      if (mk < block2)
        tmp[mk]++;
      else
        q.push(mk);
    }
    if (tmp[i] & 1) {
      unused = i;
      tmp[i] ^= 1;
    }
    int mk = i + i;
    tmp[i] /= 2;
    ans += mk * tmp[i];
    if (mk < block2)
      tmp[mk] += tmp[i];
    else
      for (int j = 0; j < tmp[i]; j++) q.push(mk);
  }
  if (unused) q.push(unused);
  while (q.size() > 1) {
    int a = q.top();
    q.pop();
    int b = q.top();
    q.pop();
    ans += a += b;
    q.push(a);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (++allcnt[a[i]] == block2) large.push_back(a[i]);
  }
  int l = 1;
  int r = 0;
  int m;
  cin >> m;
  vector<int> ans(m);
  vector<pair<int, int>> q(m);
  vector<int> t;
  for (int i = 0; i < m; i++) {
    cin >> q[i].first >> q[i].second;
    t.push_back(i);
  }
  sort(t.begin(), t.end(), [&](int a, int b) {
    int t1 = q[a].first / block;
    int t2 = q[b].first / block;
    if (t1 < t2) return true;
    if (t1 > t2) return false;
    return q[a].second < q[b].second;
  });
  for (auto i : t) {
    int tl, tr;
    tie(tl, tr) = q[i];
    while (r < tr) update(a[++r], 1);
    while (l > tl) update(a[--l], 1);
    while (r > tr) update(a[r--], -1);
    while (l < tl) update(a[l++], -1);
    ans[i] = solve();
  }
  for (int i : ans) cout << i << endl;
  return 0;
}
