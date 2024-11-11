#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 4e6 + 10;
int a[N], cnt[N], trie[N][2], tot;
long long l[31], r[31];
void ins(int x) {
  int rt = 0;
  for (int i = 30; ~i; i--) {
    int now = (x >> i & 1);
    if (!trie[rt][now]) trie[rt][now] = ++tot;
    if (now)
      r[i] += cnt[trie[rt][0]];
    else
      l[i] += cnt[trie[rt][1]];
    cnt[trie[rt][now]]++;
    rt = trie[rt][now];
  }
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], ins(a[i]);
  long long ans = 0, sum = 0;
  for (int i = 30; ~i; i--) {
    if (l[i] <= r[i])
      sum += l[i];
    else
      ans |= (1 << i), sum += r[i];
  }
  cout << sum << ' ' << ans << '\n';
  return 0;
}
