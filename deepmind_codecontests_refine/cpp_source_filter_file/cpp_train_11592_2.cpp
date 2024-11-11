#include <bits/stdc++.h>
using namespace std;
const int ms = 4 * 4 + 20;
unordered_map<int, int> mp;
int ans[4][4];
int sl[4], sc[4], sd1, sd2;
int n, sum;
bool bf(int p) {
  if (p == n * n) {
    return sd1 == sum and sd2 == sum and sl[n - 1] == sum and sc[n - 1] == sum;
  }
  int x = p / n, y = p % n;
  if (y == n - 1) {
    int v = sum - sl[x];
    if (!mp.count(v) or mp[v] == 0) return false;
    ans[x][y] = v;
    sl[x] += v;
    sc[y] += v;
    mp[v]--;
    if (x == y) sd1 += v;
    if (x + y == n - 1) sd2 += v;
    if (bf(p + 1)) return 1;
    mp[v]++;
    sl[x] -= v;
    sc[y] -= v;
    if (x == y) sd1 -= v;
    if (x + y == n - 1) sd2 -= v;
  } else if (x == n - 1) {
    int v = sum - sc[y];
    if (!mp.count(v) or mp[v] == 0) return false;
    ans[x][y] = v;
    sl[x] += v;
    sc[y] += v;
    mp[v]--;
    if (x == y) sd1 += v;
    if (x + y == n - 1) sd2 += v;
    if (bf(p + 1)) return 1;
    mp[v]++;
    sl[x] -= v;
    sc[y] -= v;
    if (x == y) sd1 -= v;
    if (x + y == n - 1) sd2 -= v;
  } else {
    for (auto &it : mp) {
      if (it.second > 0) {
        int v = it.first;
        ans[x][y] = v;
        sl[x] += v;
        sc[y] += v;
        it.second--;
        if (x == y) sd1 += v;
        if (x + y == n - 1) sd2 += v;
        if (bf(p + 1)) return 1;
        it.second++;
        sl[x] -= v;
        sc[y] -= v;
        if (x == y) sd1 -= v;
        if (x + y == n - 1) sd2 -= v;
      }
    }
  }
  return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int v;
    scanf("%d", &v);
    sum += v;
    mp[v]++;
  }
  if (n == 1) {
    printf("%lld\n%lld\n", sum, sum);
    return 0;
  }
  assert(sum % n == 0);
  sum /= n;
  bf(0);
  cout << sum << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) printf("%lld%c", ans[i][j], " \n"[j + 1 == n]);
  return 0;
}
