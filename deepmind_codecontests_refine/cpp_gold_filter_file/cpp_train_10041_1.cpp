#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int num[MAXN << 2];
int pri[MAXN << 2];
void update(int p, int x, int l = 0, int r = 10000, int rt = 1) {
  if (l == r) {
    num[rt] += x;
    pri[rt] += x * p;
    return;
  }
  int mid = (r + l) >> 1;
  if (p <= mid)
    update(p, x, l, mid, rt << 1);
  else
    update(p, x, mid + 1, r, rt << 1 | 1);
  num[rt] = num[rt << 1] + num[rt << 1 | 1];
  pri[rt] = pri[rt << 1] + pri[rt << 1 | 1];
}
int query(int k, int l = 0, int r = 10000, int rt = 1) {
  if (k <= 0) return 0;
  if (num[rt] == k) return pri[rt];
  if (l == r) return pri[rt] / num[rt] * k;
  int mid = (r + l) >> 1;
  if (num[rt << 1] >= k)
    return query(k, l, mid, rt << 1);
  else
    return pri[rt << 1] + query(k - num[rt << 1], mid + 1, r, rt << 1 | 1);
}
int votes[MAXN];
bool cmp(int a, int b) { return votes[a] > votes[b]; }
int main() {
  int n, a, b;
  cin >> n;
  map<int, multiset<int> > mm;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a) mm[a].insert(b);
    update(b, 1);
  }
  int f[MAXN], cnt = 0;
  map<int, multiset<int> >::iterator it = mm.begin();
  for (; it != mm.end(); it++) {
    f[cnt++] = it->first;
    votes[it->first] = it->second.size();
  }
  sort(f, f + cnt, cmp);
  int vsum = 0, vnum = 0, end = 0;
  int ans = 2e9;
  for (int i = n; i >= 1; i--) {
    while (end < cnt && votes[f[end]] >= i) end++;
    for (int j = 0; j < end; j++) {
      multiset<int>::iterator it;
      it = mm[f[j]].begin();
      int price = *it;
      vsum += price;
      vnum++;
      update(price, -1);
      mm[f[j]].erase(it);
    }
    ans = min(ans, vsum + query(i - vnum));
  }
  cout << ans << endl;
}
