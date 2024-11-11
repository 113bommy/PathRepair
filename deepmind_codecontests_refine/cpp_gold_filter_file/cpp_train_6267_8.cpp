#include <bits/stdc++.h>
using namespace std;
long long n, cnt = 0, x, ans = 1e18;
long pos[100005];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1) pos[cnt++] = i;
  }
  if (cnt < 2) return cout << -1, 0;
  vector<int> res;
  for (int i = 2; i <= sqrt(cnt); i++)
    if (cnt % i == 0) {
      res.push_back(i);
      if (i * i != cnt) res.push_back(cnt / i);
    }
  res.push_back(cnt);
  int p = 0;
  while (p < res.size()) {
    int j = 0;
    long long anss = 0;
    while (j < cnt) {
      for (int i = j; i < j + res[p]; i++)
        anss += abs(pos[i] - pos[j + res[p] / 2]);
      j += res[p];
    }
    ans = min(ans, anss);
    p++;
  }
  cout << ans;
  return 0;
}
