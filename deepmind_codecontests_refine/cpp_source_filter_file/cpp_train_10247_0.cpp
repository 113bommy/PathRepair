#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > cost[200002];
typedef struct type {
  long long int e;
  long long int pts;
  int idx;
} type;
int vis[200002];
type a[200002];
type b[200002];
int compare(const type &a, const type &b) { return a.e < b.e; }
int compare1(const type &a, const type &b) { return a.pts > b.pts; }
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].pts);
    scanf("%d", &a[i].e);
    b[i].pts = a[i].pts;
    b[i].e = a[i].e;
    a[i].idx = i;
    b[i].idx = i;
    cost[a[i].pts].push_back(make_pair(a[i].e, i));
  }
  if (k == n + 1) {
    printf("0\n");
    return 0;
  }
  sort(a, a + n, compare);
  sort(b, b + n, compare1);
  int req = b[k - 1].pts - 1;
  long long int ans = -1;
  for (int itr = 0; itr < 2; itr++) {
    int pts = 0;
    req++;
    long long int cnt = 0;
    long long int bt = 0;
    for (int j = 0; j < n; j++) {
      if (b[j].pts < req - 1) {
        bt++;
      }
    }
    memset(vis, 0, sizeof vis);
    vector<pair<int, int> > tmp;
    for (int i = 0; i < cost[req].size(); i++) tmp.push_back(cost[req][i]);
    if (req != 0)
      for (int i = 0; i < cost[req - 1].size(); i++)
        tmp.push_back(cost[req - 1][i]);
    sort(tmp.begin(), tmp.end());
    if (n + 1 - k - bt > tmp.size()) continue;
    for (int i = 0; i < n + 1 - k - bt; i++) {
      cnt = cnt + tmp[i].first;
      vis[tmp[i].second] = 1;
      pts++;
    }
    for (int i = 0; i < n; i++) {
      if (pts >= req) break;
      if (vis[a[i].idx]) continue;
      pts++;
      cnt = cnt + a[i].e;
      if (pts >= req) {
        break;
      }
    }
    if (pts < req) continue;
    if (ans == -1)
      ans = cnt;
    else
      ans = min(ans, cnt);
  }
  cout << ans << endl;
}
