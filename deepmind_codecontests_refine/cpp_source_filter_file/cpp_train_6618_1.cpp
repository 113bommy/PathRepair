#include <bits/stdc++.h>
using namespace std;
string s, t, n1, n2;
int n;
map<string, int> rr;
vector<pair<int, string> > a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> n;
  for (int i = 0; i < n; ++i) {
    cin >> n1 >> t;
    if (t == "posted") {
      cin >> t >> n2 >> t;
      n2.erase((int)n2.size() - 2, 2);
      int add = 0;
      if (n1 != s && n2 != s)
        add = 0;
      else
        add = 15;
      rr[n1] += add;
      rr[n2] += add;
    } else if (t == "commented") {
      cin >> t >> n2 >> t;
      n2.erase((int)n2.size() - 2, 2);
      int add = 0;
      if (n1 != s && n2 != s)
        add = 0;
      else
        add = 10;
      rr[n1] += add;
      rr[n2] += add;
    } else {
      cin >> n2 >> t;
      n2.erase((int)n2.size() - 2, 2);
      int add = 0;
      if (n1 != s && n2 != s)
        add = 0;
      else
        add = 10;
      rr[n1] += add;
      rr[n2] += add;
    }
  }
  for (map<string, int>::iterator it = rr.begin(); it != rr.end(); ++it)
    a.push_back(make_pair(-it->second, it->first));
  sort(a.begin(), a.end());
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i].second != s) cout << a[i].second << '\n';
  return 0;
}
