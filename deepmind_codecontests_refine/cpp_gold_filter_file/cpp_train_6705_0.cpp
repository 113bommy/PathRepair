#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 2;
const long long INF = 5e8;
const long long Mod = 998244353;
const int SQRT = 333;
int n, m, q;
long long a[N];
long long add[N], sum[N];
bool isHeavy[N];
vector<int> s[N];
map<int, int> H[N], L[N];
vector<int> cntHH[N], cntLH[N];
vector<int> Heavy;
int idx[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int k;
    cin >> k;
    isHeavy[i] = k > SQRT;
    if (isHeavy[i]) {
      idx[i] = Heavy.size();
      Heavy.push_back(i);
    }
    while (k--) {
      int x;
      cin >> x;
      s[i].push_back(x);
      if (isHeavy[i])
        sum[i] += a[x], H[x][i]++;
      else
        L[x][i]++;
    }
  }
  int z = Heavy.size();
  for (int i = 1; i <= m; i++)
    if (isHeavy[i])
      cntHH[i].resize(z, 0);
    else
      cntLH[i].resize(z, 0);
  for (int i = 1; i <= n; i++)
    for (auto j : H[i]) {
      for (auto k : H[i])
        cntHH[j.first][idx[k.first]] += min(j.second, k.second);
      for (auto k : L[i])
        cntLH[k.first][idx[j.first]] += min(j.second, k.second);
    }
  while (q--) {
    char c;
    cin >> c;
    int x, y = 0;
    cin >> x;
    if (c == '+') {
      cin >> y;
      if (isHeavy[x]) {
        add[x] += y;
        for (int i : Heavy) sum[i] += (long long)cntHH[x][idx[i]] * y;
      } else {
        for (int i : Heavy) sum[i] += (long long)cntLH[x][idx[i]] * y;
        for (int i : s[x]) a[i] += y;
      }
    } else {
      if (isHeavy[x])
        cout << sum[x] << '\n';
      else {
        long long sum = 0;
        for (int i : Heavy) sum += (long long)add[i] * cntLH[x][idx[i]];
        for (int i : s[x]) sum += a[i];
        cout << sum << '\n';
      }
    }
  }
  return 0;
}
