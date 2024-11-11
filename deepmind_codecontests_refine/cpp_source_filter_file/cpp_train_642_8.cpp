#include <bits/stdc++.h>
using namespace std;
int n, tc;
int mi[200005], pi[200005];
vector<int> id;
bool cmp(int a, int b) { return mi[a] < mi[b]; }
void revalue() {
  id.clear();
  for (int i = 1; i <= n; i++) id.push_back(i);
  sort(id.begin(), id.end(), cmp);
  long long cur = mi[id[0]] - 1;
  int pos = 0;
  priority_queue<pair<long long, int> > pq;
  while (pos < n || !pq.empty()) {
    cur = cur + 1;
    if (pq.empty() && mi[id[pos]] > cur) {
      cur = mi[id[pos]];
      continue;
    }
    while (pos < n && mi[id[pos]] <= cur) {
      pq.push(make_pair(pi[id[pos]], id[pos]));
      pos++;
    }
    mi[pq.top().second] = cur;
    pq.pop();
  }
  sort(id.begin(), id.end(), cmp);
}
int check(int N) {
  int cnt = N;
  for (int i = 0; i < n && cnt < n; i++) {
    if (mi[id[i]] <= cnt) {
      cnt++;
    } else
      return 0;
  }
  return cnt >= n;
}
long long sufsum(int N) {
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += pi[id[n - i - 1]];
  }
  return ans;
}
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &mi[i], &pi[i]);
    revalue();
    int l = 0, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(m))
        r = m;
      else
        l = m + 1;
    }
    printf("%lld\n", sufsum(l));
  }
  return 0;
}
