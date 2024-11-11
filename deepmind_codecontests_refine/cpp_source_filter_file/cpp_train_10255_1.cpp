#include <bits/stdc++.h>
using namespace std;
int p[2001], q[2001], r[2001], s[2001];
int n;
vector<pair<int, int> > ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    p[a] = i;
    s[i] = a;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a;
    q[a] = i;
    r[i] = a;
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    int x = r[i];
    while (p[x] != i) {
      int j, y;
      for (j = p[x] - 1; j >= i; j--) {
        y = s[j];
        if (q[y] >= p[x]) break;
      }
      c += abs(p[x] - j);
      ans.push_back(make_pair(x, y));
      s[j] = x;
      s[p[x]] = y;
      p[y] = p[x];
      p[x] = j;
    }
  }
  cout << c << '\n';
  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << '\n';
  return 0;
}
