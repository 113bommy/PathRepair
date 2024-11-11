#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[100005], i, mx = 0;
  vector<int> ad;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  ad.push_back(0);
  for (i = 1; i < n; i++)
    if (a[i] == a[i - 1]) ad.push_back(i - 1);
  ad.push_back(n);
  for (i = 1; i < ad.size(); i++) mx = max(mx, ad[i] - ad[i - 1]);
  cout << mx << endl;
}
