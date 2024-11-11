#include <bits/stdc++.h>
using namespace std;
const long long MAXN = +100500;
const long long INF = 1e18;
map<long long, long long> b;
map<long long, long long> s;
int main() {
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    char t;
    cin >> t;
    long long x, y;
    cin >> x >> y;
    if (t == 'S') {
      s[x] += y;
    } else {
      b[x] += y;
    }
  }
  long long cnt = 0;
  long long cur = 0;
  vector<pair<long long, long long> > ans;
  while (cur <= MAXN && cnt < k) {
    if (s[cur] > 0) {
      ans.push_back(make_pair(cur, s[cur]));
      cnt++;
    }
    cur++;
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << "S " << ans[i].first << " " << ans[i].second << endl;
  }
  cur = MAXN;
  cnt = 0;
  while (cur >= 0 && cnt < k) {
    if (b[cur] > 0) {
      cout << 'B' << " " << cur << " " << b[cur] << endl;
      cnt++;
    }
    cur--;
  }
}
