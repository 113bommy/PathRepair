#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    if (d <= n) {
      cout << "YES\n";
      continue;
    }
    vector<int> v;
    int opt = (int)sqrt(d);
    for (int i = max(opt - 20, 0); i <= opt + 20; i++) {
      int brp = i + (int)ceil((double)d / ((double)i + 1.0));
      v.push_back(brp);
    }
    sort(v.begin(), v.end());
    if (v[0] <= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
