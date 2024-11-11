#include <bits/stdc++.h>
using namespace std;
int n, m, q, bit[1 << 16], cnt[2005];
struct cmp {
  bool operator()(int a, int b) {
    return cnt[a] != cnt[b] ? cnt[a] < cnt[b] : a < b;
  }
};
set<int> cer;
set<int, cmp> seq;
vector<int> vec[2005];
int cal(int r) {
  int ret = 0;
  for (int i = 0; i <= (m - 1) / 32; i++)
    ret += bit[vec[r][i] & (1 << 16) - 1] + bit[vec[r][i] >> 16];
  return ret;
}
bool contain(int r1, int r2) {
  for (int i = 0; i <= (m - 1) / 32; i++)
    if ((vec[r1][i] & vec[r2][i]) != vec[r2][i]) return false;
  return true;
}
void chk(int r) {
  auto it = seq.find(r);
  it++;
  if (it != seq.end()) {
    int row = *it;
    if (contain(r, row) || contain(row, r)) return;
    cer.insert(r);
  }
}
int get(int r1, int r2) {
  for (int i = 0; i <= (m - 1) / 32; i++)
    if ((vec[r1][i] & vec[r2][i]) != vec[r2][i])
      for (int j = 0; j <= 31; j++)
        if (!(vec[r1][i] & 1ll << j) && vec[r2][i] & 1ll << j)
          return i * 32 + j;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= (1 << 16) - 1; i++)
    for (int j = 0; j <= 15; j++)
      if (i & 1 << j) bit[i]++;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) vec[i].resize((m - 1) / 32 + 1);
  while (q--) {
    int a, l, r;
    cin >> a >> l >> r;
    l--;
    r--;
    cer.erase(a);
    for (int i = 0; i <= (m - 1) / 32; i++) {
      if (l <= i * 32 && r >= i * 32 + 31)
        vec[a][i] ^= (1ll << 32) - 1;
      else if (i * 32 <= l && r <= i * 32 + 31)
        vec[a][i] ^= (1ll << r - l + 1) - 1 << l % 32;
      else if (i * 32 + 31 >= l && i * 32 + 31 < r)
        vec[a][i] ^= (1ll << 32 - l % 32) - 1 << l % 32;
      else if (r >= i * 32 && l < i * 32)
        vec[a][i] ^= (1ll << r % 32 + 1) - 1;
    }
    auto it = seq.find(a);
    if (it != seq.begin()) {
      it--;
      cer.erase(*it);
      seq.erase(a);
      chk(*it);
    } else
      seq.erase(a);
    cnt[a] = cal(a);
    it = seq.insert(a).first;
    if (it != seq.begin()) {
      it--;
      cer.erase(*it);
      chk(*it);
      chk(a);
    } else
      chk(a);
    if (cer.empty())
      cout << -1 << '\n';
    else {
      int r1 = *cer.begin();
      auto it = seq.find(r1);
      it++;
      int r2 = *it, c1 = get(r1, r2), c2 = get(r2, r1);
      if (r1 > r2) swap(r1, r2);
      if (c1 > c2) swap(c1, c2);
      cout << r1 << ' ' << c1 + 1 << ' ' << r2 << ' ' << c2 + 1 << '\n';
    }
  }
  return 0;
}
