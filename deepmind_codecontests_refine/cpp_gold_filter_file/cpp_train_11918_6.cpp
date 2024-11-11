#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 100 * 1000 + 100;
const long long o = 1000 * 1000 * 1000;
const long long oo = o * o;
long long d[maxn], h[maxn];
pair<long long, long long> seg1[4 * maxn], seg2[4 * maxn];
long long dis[maxn];
int n, a, b, m;
vector<long long> ans;
void update1(long long val, int ind, int x, int segl, int segr);
void update2(long long val, int ind, int x, int segl, int segr);
pair<long long, long long> getans1(int ql, int qr, int x, int segl, int segr);
pair<long long, long long> getans2(int ql, int qr, int x, int segl, int segr);
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < n; i++) cin >> h[i];
  dis[0] = 0;
  for (int i = 1; i < 2 * n; i++) dis[i] = dis[i - 1] + d[(i - 1) % n];
  for (int i = 0; i < 2 * n; i++) {
    update1(dis[i] + 2 * h[i % n], i, 1, 0, 2 * n);
    update2(dis[i] - 2 * h[i % n], i, 1, 0, 2 * n);
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    if (a <= b) {
      long long ans1 = 0, ans2 = 0;
      pair<long long, long long> tmp1 = getans1(b + 1, a + n, 1, 0, 2 * n);
      update2(oo, tmp1.second, 1, 0, 2 * n);
      pair<long long, long long> tmp2 = getans2(b + 1, a + n, 1, 0, 2 * n);
      ans1 = tmp1.first - tmp2.first;
      update2(tmp1.first - 4 * h[(tmp1.second) % n], tmp1.second, 1, 0, 2 * n);
      tmp2 = getans2(b + 1, a + n, 1, 0, 2 * n);
      update1(-oo, tmp2.second, 1, 0, 2 * n);
      tmp1 = getans1(b + 1, a + n, 1, 0, 2 * n);
      ans2 = tmp1.first - tmp2.first;
      update1(tmp2.first + 4 * h[(tmp2.second) % n], tmp2.second, 1, 0, 2 * n);
      ans.push_back(max(ans1, ans2));
    } else {
      long long ans1 = 0, ans2 = 0;
      pair<long long, long long> tmp1 = getans1(b + 1, a, 1, 0, 2 * n);
      update2(oo, tmp1.second, 1, 0, 2 * n);
      pair<long long, long long> tmp2 = getans2(b + 1, a, 1, 0, 2 * n);
      ans1 = tmp1.first - tmp2.first;
      update2(tmp1.first - 4 * h[(tmp1.second) % n], tmp1.second, 1, 0, 2 * n);
      tmp2 = getans2(b + 1, a, 1, 0, 2 * n);
      update1(-oo, tmp2.second, 1, 0, 2 * n);
      tmp1 = getans1(b + 1, a, 1, 0, 2 * n);
      ans2 = tmp1.first - tmp2.first;
      update1(tmp2.first + 4 * h[(tmp2.second) % n], tmp2.second, 1, 0, 2 * n);
      ans.push_back(max(ans1, ans2));
    }
  }
  for (auto i : ans) cout << i << '\n';
  return 0;
}
void update1(long long val, int ind, int x, int segl, int segr) {
  if (segr - segl < 2) {
    seg1[x] = pair<long long, long long>(val, ind);
    return;
  }
  int mid = (segl + segr) / 2;
  if (ind < mid)
    update1(val, ind, 2 * x, segl, mid);
  else
    update1(val, ind, 2 * x + 1, mid, segr);
  seg1[x] = max(seg1[2 * x], seg1[2 * x + 1]);
}
void update2(long long val, int ind, int x, int segl, int segr) {
  if (segr - segl < 2) {
    seg2[x] = pair<long long, long long>(val, ind);
    return;
  }
  int mid = (segl + segr) / 2;
  if (ind < mid)
    update2(val, ind, 2 * x, segl, mid);
  else
    update2(val, ind, 2 * x + 1, mid, segr);
  seg2[x] = min(seg2[2 * x], seg2[2 * x + 1]);
}
pair<long long, long long> getans1(int ql, int qr, int x, int segl, int segr) {
  if (ql <= segl && qr >= segr) return seg1[x];
  pair<long long, long long> res = pair<long long, long long>(0, 0);
  int mid = (segl + segr) / 2;
  if (ql < mid) res = max(res, getans1(ql, qr, 2 * x, segl, mid));
  if (qr > mid) res = max(res, getans1(ql, qr, 2 * x + 1, mid, segr));
  return res;
}
pair<long long, long long> getans2(int ql, int qr, int x, int segl, int segr) {
  if (ql <= segl && qr >= segr) return seg2[x];
  pair<long long, long long> res = pair<long long, long long>(oo, oo);
  int mid = (segl + segr) / 2;
  if (ql < mid) res = min(res, getans2(ql, qr, 2 * x, segl, mid));
  if (qr > mid) res = min(res, getans2(ql, qr, 2 * x + 1, mid, segr));
  return res;
}
