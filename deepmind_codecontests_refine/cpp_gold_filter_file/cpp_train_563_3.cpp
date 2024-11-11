#include <bits/stdc++.h>
using namespace std;
const int maxn = 312345;
int n, p;
int cnt[maxn], acc[maxn];
map<int, int> G[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> p;
  for (int(i) = (1); (i) <= (n); (i)++) {
    int x, y;
    cin >> x >> y;
    G[x][y]++;
    G[y][x]++;
    cnt[x]++, cnt[y]++;
  }
  for (int(i) = (1); (i) <= (n); (i)++) acc[cnt[i]]++;
  for (int(i) = (n); (i) >= (0); (i)--) acc[i] += acc[i + 1];
  long long ans = 0;
  for (int(i) = (1); (i) <= (n); (i)++) {
    int need = max(p - cnt[i], 0);
    int now = acc[need] - (cnt[i] >= need);
    for (auto [j, c] : G[i])
      if (cnt[j] >= need && cnt[i] + cnt[j] - c < p) now--;
    ans += now;
  }
  cout << ans / 2;
}
