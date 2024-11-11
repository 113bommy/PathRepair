#include <bits/stdc++.h>
using namespace std;
struct peyr {
  int x, id;
  peyr(){};
  ~peyr(){};
  peyr(int a, int b) : x(a), id(b){};
};
bool operator<(peyr a, peyr b) { return a.x < b.x; }
const int maxn = 100 * 1000 + 7;
int n;
int a[maxn], id[maxn], pre[maxn], suf[maxn];
peyr s[maxn];
int read(int idx, int *fen) {
  int sum = 0;
  while (idx > 0) {
    sum += fen[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, int val, int *fen) {
  if (idx == 0) return;
  while (idx < maxn) {
    fen[idx] += val;
    idx += (idx & -idx);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s[i].x = a[i];
    s[i].id = i;
  }
  sort(s, s + n);
  int lst_id = 1;
  id[s[0].id] = 1;
  for (int i = 1; i < n; ++i)
    if (s[i - 1].x == s[i].x)
      id[s[i].id] = lst_id;
    else
      id[s[i].id] = ++lst_id;
  int r = n - 1;
  update(id[r], 1, suf);
  long long inv = 0;
  while (r > 0) {
    r--;
    inv += read(id[r] - 1, suf);
    if (inv > k) {
      inv -= read(id[r] - 1, suf);
      r++;
      break;
    }
    update(id[r], 1, suf);
  }
  if (r == 0) {
    cout << 1LL * n * (n - 1) / 2 << "\n";
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    inv += i - read(id[i], pre) + read(id[i] - 1, suf);
    update(id[i], 1, pre);
    while (inv > k) {
      if (r == n - 1) goto hell;
      inv -= i + 1 - read(id[r], pre) + read(id[r] - 1, suf);
      update(id[r], -1, suf);
      r++;
    }
    ans += n - r;
  }
hell:
  cout << ans << "\n";
  return 0;
}
