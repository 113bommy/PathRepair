#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 100005;
vector<pair<long long, long long> > s[30];
char str[maxn];
long long a[30];
long long sum[maxn];
int main() {
  for (int i = 0; i < 26; i++) cin >> a[i];
  scanf("%s", str);
  int n = strlen(str);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[str[i] - 'a'];
    s[str[i] - 'a'].push_back(pair<long long, long long>(sum[i + 1], i));
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    if (s[i].size()) {
      sort(s[i].begin(), s[i].end());
      int sz = s[i].size();
      for (int j = 0; j < sz; j++) {
        int l =
            lower_bound(s[i].begin(), s[i].end(),
                        pair<long long, long long>(
                            s[i][j].first - a[str[s[i][j].second] - 'a'], -1)) -
            s[i].begin();
        int r = upper_bound(s[i].begin(), s[i].end(),
                            pair<long long, long long>(
                                s[i][j].first - a[str[s[i][j].second] - 'a'],
                                s[i][j].second)) -
                s[i].begin();
        ans += r - l;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
