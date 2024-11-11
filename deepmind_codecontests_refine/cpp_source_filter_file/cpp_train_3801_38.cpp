#include <bits/stdc++.h>
using namespace std;
bool vis[10001010];
vector<pair<long long, long long> > box;
int main() {
  long long int n;
  cin >> n;
  for (int i = 1; i <= min(n, (long long)1000000); i++) {
    if (vis[i]) continue;
    long long int m = i;
    long long v;
    long long int div;
    long long ans;
    v = m * (m - 1);
    v = v / 2;
    v = v * m;
    v = v * -1;
    v += ((m * (m - 1) * (2 * m - 1)) / 6);
    v -= n;
    div = ((m * (m - 1)) / 2 - m * m);
    if (div == 0 || v % div != 0) continue;
    ans = v / div;
    if (ans >= m && ans <= 1000000000000000000) {
      vis[i] = 1;
      box.push_back(make_pair(m, ans));
      if (m != ans) box.push_back(make_pair(ans, m));
    } else if (ans > 1000000000000000000)
      break;
  }
  cout << box.size() << endl;
  sort(box.begin(), box.end());
  for (int i = 0; i < box.size(); i++) {
    cout << box[i].first << " " << box[i].second << endl;
  }
}
