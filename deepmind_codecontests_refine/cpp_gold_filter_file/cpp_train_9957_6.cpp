#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 1e9;
const long long LINF = INF * INF;
const int MAX = 1 << 19;
int p[MAX];
vector<int> d[MAX];
int tau(int n) {
  int res = 1;
  while (n > 1) {
    int q = p[n];
    int cnt = 0;
    while (n % q == 0) cnt++, n /= q;
    res *= cnt + 1;
  }
  return res;
}
void bad() {
  cout << "No" << endl;
  exit(0);
}
bool ok(vector<int>& a, int k) {
  int res = 0;
  for (int i = (0); i < ((int)((a).size())); ++i)
    for (int j = (i + 1); j < ((int)((a).size())); ++j) res += a[j] % a[i] == 0;
  return res == k;
}
int cnt[MAX];
bool deleted[MAX];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = (2); i < (MAX); ++i) p[i] = i;
  for (int i = (2); i < (MAX); ++i)
    if (p[i] == i)
      for (long long j = i * (long long)i; j < MAX; j += i)
        if (p[j] == j) p[j] = i;
  int n, k;
  cin >> n >> k;
  int total = 0;
  for (int i = (1); i < (n + 1); ++i) {
    total += tau(i) - 1;
    if (total >= k) {
      n = i;
      break;
    }
  }
  if (total < k) bad();
  cout << "Yes" << endl;
  int lyshni = total - k;
  for (int i = (1); i < (n + 1); ++i)
    for (int j = i + i; j <= n; j += i) cnt[j]++, cnt[i]++, d[j].push_back(i);
  while (lyshni) {
    int mx = -1;
    for (int i = (n + 1) - 1; i >= (1); --i) {
      if (deleted[i]) continue;
      if (cnt[i] <= lyshni && (mx == -1 || cnt[i] > cnt[mx])) mx = i;
    }
    int i = mx;
    lyshni -= cnt[i];
    deleted[i] = 1;
    for (int j = i + i; j <= n; j += i) cnt[j]--;
    for (auto j : d[i]) cnt[j]--;
  }
  vector<int> ans;
  for (int i = (1); i < (n + 1); ++i)
    if (!deleted[i]) ans.push_back(i);
  cout << (int)((ans).size()) << endl;
  for (auto i : ans) cout << i << ' ';
  cout << endl;
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
