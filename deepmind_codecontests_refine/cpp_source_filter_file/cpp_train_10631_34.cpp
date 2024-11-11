#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, x = 0, ad = 0, md = 0;
  cin >> n;
  vector<int> v(n);
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = n - 1; i >= 0; --i) {
    v[i] += x;
    md = v[i] % n;
    if (md <= i)
      ad = i - md;
    else
      ad = n - md + i;
    x += ad;
    ans.push_back({i + 1, ad});
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << 1 << " " << it.first << " " << it.second << "\n";
  }
  cout << 2 << " " << n << " " << n;
  return 0;
}
