#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
string s[maxn];
long long n, k, maxpref[maxn];
vector<long long> get(int l, int r) {
  vector<long long> ans(r - l + 2);
  if (r - l < 2) return {0, 0};
  int mid = l;
  for (int i = l + 1; i < r - 1; i++)
    if (maxpref[i] < maxpref[mid]) mid = i;
  vector<long long> ansl = get(l, mid + 1), ansr = get(mid + 1, r);
  for (int i = 0; i < ansl.size(); i++)
    for (int j = 0; j < ansr.size(); j++)
      ans[i + j] = max(ans[i + j], ansl[i] + ansr[j] + i * j * maxpref[mid]);
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < min(s[i].size(), s[i + 1].size()); j++) {
      if (s[i][j] != s[i + 1][j]) break;
      maxpref[i] = j + 1;
    }
  vector<long long> ans = get(0, n);
  cout << ans[k] << endl;
  return 0;
}
