#include <bits/stdc++.h>
using namespace std;
int n;
long long v[4123], d[4123], p[4123];
vector<int> ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i] >> d[i] >> p[i];
  for (int i = 1; i <= n; i++) {
    if (p[i] < 0) continue;
    ans.push_back(i);
    long long t = v[i];
    long long h = 0;
    for (int j = i + 1; j <= n; j++) {
      if (p[j] < 0) continue;
      p[j] -= (t + h);
      if (p[j] < 0) h += d[j];
      if (t) t--;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
