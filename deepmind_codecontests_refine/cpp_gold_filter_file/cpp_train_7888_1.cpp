#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);

  for (int i = 0; i < n; i++) {
    int x, l;
    cin >> x >> l;
    p[i].first = x + l;
    p[i].second = x - l;
  }

  sort(begin(p), end(p));

  int cur = -2000000001;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (cur <= p[i].second) {
      ans++;
      cur = p[i].first;
    }
  }

  cout << ans << endl;
}
