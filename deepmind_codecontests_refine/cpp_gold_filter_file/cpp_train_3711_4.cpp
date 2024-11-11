#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
const double PI = acos(-1);
const double eps = (1e-9);
const long long int INF = 2e18;
const int M = (1e9) + 7;
const int fft = 998244353;
const int N = (4e5) + 3;
const int B = 62;
vector<long long int> ad[B];
int cnt[B], num[B];
int bit(long long int y) {
  int a = 0;
  while (y > 1) a++, y /= 2;
  return a;
}
void solve() {
  int n, i, b;
  scanf("%d", &n);
  long long int a, x = INF;
  for (i = 0; i < n; ++i)
    scanf("%lld", &a), b = bit(a), ad[b].push_back(a), x = min(x, a);
  for (i = 0; i < B; ++i)
    sort(ad[i].begin(), ad[i].end()), num[i] = (int)ad[i].size();
  vector<long long int> ans;
  ans.push_back(x);
  b = bit(x);
  cnt[b]++;
  while (1) {
    for (i = 0; i < B; ++i) {
      if ((!((x >> i) & 1)) && cnt[i] < num[i]) break;
    }
    if (i == B) break;
    a = ad[i][cnt[i]];
    ans.push_back(a);
    x ^= a, cnt[i]++;
  }
  if ((int)ans.size() < n)
    printf("No\n");
  else {
    printf("Yes\n");
    for (i = 0; i < n; ++i) cout << ans[i] << " ";
  }
}
int main() {
  int t = 1;
  while (t--) solve();
}
