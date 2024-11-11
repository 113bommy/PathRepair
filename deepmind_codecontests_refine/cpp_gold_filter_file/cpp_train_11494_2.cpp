#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
long long mod = 1000000007;
vector<int> ans;
bool visit[100005];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n & 1) {
    cout << -1;
    return 0;
  }
  int now = 0;
  for (int i = 0; i < (int)(n + 1); i++) {
    ans.push_back(now);
    if (!visit[(now + n) / 2])
      now = (now + n) / 2;
    else if (!visit[now / 2])
      now = now / 2;
    visit[now] = true;
  }
  reverse(ans.begin(), ans.end());
  for (int j = (int)(0); j < (int)(ans.size() + 0); j++) {
    if (j > 0) cout << ' ';
    cout << ans[j];
  };
  return 0;
}
