#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> w[4];
int n, m;
long long GetAns(int t) {
  int totw = m;
  long long ans = 0;
  for (int i = 0; i < min(t, (int)w[3].size()); i++) {
    totw -= 3;
    ans += w[3][i];
  }
  if (totw < 0) return 0;
  int p1 = 0, p2 = 0;
  while (totw >= 2 && p2 < w[2].size()) {
    totw -= 2;
    ans += w[2][p2++];
  }
  while (totw >= 1 && p1 < w[1].size()) {
    totw--;
    ans += w[1][p1++];
  }
  while (p1 + 1 < w[1].size() && p2 >= 1 &&
         w[1][p1] + w[1][p1 + 1] > w[2][p2 - 1]) {
    ans += w[1][p1] + w[1][p1 + 1];
    p1 += 2;
    p2--;
    ans -= w[2][p2];
  }
  if (p1 < w[1].size() && p2 >= 1 && w[1][p1] > w[2][p2 - 1]) {
    ans += w[1][p1];
    p1++;
    p2--;
    ans -= w[2][p2];
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    w[x].push_back(y);
  }
  for (auto &v : w) sort(v.begin(), v.end(), greater<int>());
  int L = 0, R = min((int)w[3].size(), m / 3);
  while (R - L > 10) {
    int mid = L + R >> 1;
    int mmid = (mid + R) >> 1;
    if (GetAns(mid) < GetAns(mmid))
      L = mid;
    else
      R = mmid;
  }
  long long ans = 0;
  for (int i = L; i <= R; i++) ans = max(ans, GetAns(i));
  printf("%lld\n", ans);
  return 0;
}
