#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const long long INF = 1000000000ll;
const long long LLINF = 1000000000000000000ll;
const int MOD = 1000000007;
int a[MAXN];
vector<int> ans[1000];
vector<pair<int, int>> cnt;
int cur = 0;
int curI = 0;
int nxt(int n) {
  if (curI > min(cnt[cur].second - 1, n)) {
    cur++;
    curI = 0;
  }
  curI++;
  return cnt[cur].first;
}
bool cmp(pair<int, int> x, pair<int, int> y) { return x.second > y.second; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cnt.push_back({a[0], 1});
  for (int i = (int)1; i <= (int)(n - 1); i++) {
    if (a[i] == a[i - 1]) {
      cnt.back().second++;
    } else {
      cnt.push_back({a[i], 1});
    }
  }
  sort(cnt.begin(), cnt.end(), cmp);
  int q = sqrt(n);
  long long res = 1;
  long long resN = 1;
  for (int i = (int)1; i <= (int)(q); i++) {
    long long c = 0;
    for (int j = 0; j < (int)(cnt.size()); j++) {
      c += min(i, cnt[j].second);
    }
    if (c / i < i) {
      continue;
    }
    if (i * (c / i) > res) {
      res = i * (c / i);
      resN = i;
    }
  }
  long long resM = res / resN;
  cout << res << "\n";
  cout << resN << " " << resM << "\n";
  for (int i = 0; i < (int)(resN); i++) {
    ans[i].resize(resM);
  }
  for (int k = 0; k < (int)(resM); k++) {
    for (int i = 0; i < (int)(resN); i++) {
      ans[i][(i + k) % resM] = nxt(resN);
    }
  }
  for (int i = 0; i < (int)(resN); i++) {
    for (int j = 0; j < (int)(resM); j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
