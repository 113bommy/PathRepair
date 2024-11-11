#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 11;
pair<int, int> a[N];
int b[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 1; i <= n; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  long long t = 0;
  for (int i = 1; i <= n; i++) t += 1ll * (a[i].first - b[i]);
  if (t != 0) {
    cout << "NO" << endl;
    return 0;
  }
  set<pair<int, int> > st1, st2;
  for (int i = 1; i <= n; i++)
    if (a[i].first < b[i])
      st1.insert(make_pair(a[i].first, i));
    else if (a[i].first > b[i])
      st2.insert(make_pair(a[i].first, i));
  vector<pair<int, pair<int, int> > > vv;
  while (st1.size() > 0 && st2.size() > 0) {
    pair<int, int> p1 = *st1.rbegin();
    auto it = st2.lower_bound(make_pair(p1.first + 2, -1));
    if (it == st2.end()) {
      cout << "NO\n";
      return 0;
    }
    pair<int, int> p2 = *it;
    st1.erase(p1);
    st2.erase(p2);
    if (p1.first >= p2.first) {
      cout << "NO\n";
      return 0;
    }
    int l = p1.second, r = p2.second;
    int c = min(b[l] - a[l].first, a[r].first - b[r]);
    c = min(c, (a[r].first - a[l].first) / 2);
    if (c == 0) {
      cout << "NO\n";
      return 0;
    }
    vv.push_back(make_pair(a[l].second, make_pair(a[r].second, c)));
    a[l].first += c;
    a[r].first -= c;
    if (a[l].first != b[l]) st1.insert(make_pair(a[l].first, l));
    if (a[r].first != b[r]) st2.insert(make_pair(a[r].first, r));
  }
  cout << "YES\n";
  cout << vv.size() << "\n";
  for (int j = 0; j < vv.size(); j++)
    cout << vv[j].first << " " << vv[j].second.first << " "
         << vv[j].second.second << "\n";
}
