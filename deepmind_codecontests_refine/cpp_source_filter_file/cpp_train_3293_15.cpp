#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 5];
  for (int i = 0; i < n; i++) cin >> arr[i];
  set<pair<int, pair<int, int> > > s;
  set<int> so;
  map<int, int> m, e;
  int ind = 0, i, cnt = 1, lol = 0;
  for (i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1])
      cnt++;
    else {
      s.insert(make_pair(-cnt, make_pair(lol, arr[i - 1])));
      m[lol] = -cnt;
      e[lol] = arr[i - 1];
      so.insert(lol);
      lol++;
      cnt = 1;
    }
  }
  s.insert(make_pair(-cnt, make_pair(lol, arr[i - 1])));
  m[lol] = -cnt;
  e[lol] = arr[i - 1];
  so.insert(lol);
  set<pair<int, pair<int, int> > >::iterator it, it1, it2;
  set<int>::iterator ita, ita1, ita2;
  int ans = 0;
  while (s.size() != 0) {
    ans++;
    it = s.begin();
    s.erase(it);
    ita = so.find(it->second.first);
    so.erase(ita);
    ita1 = so.lower_bound((*ita));
    if (ita1 == so.begin()) continue;
    ita1--;
    ita2 = so.lower_bound(*ita);
    if (ita2 == so.end()) continue;
    it1 = s.find(make_pair(m[*ita1], make_pair(*ita1, e[*ita1])));
    it2 = s.find(make_pair(m[*ita2], make_pair(*ita2, e[*ita2])));
    if (it1 != s.end() && it2 != s.end() && e[*ita1] == e[*ita2]) {
      s.erase(it1);
      s.erase(it2);
      s.insert(make_pair(m[*ita1] + m[*ita2], make_pair(*ita1, e[*ita1])));
      so.erase(*ita2);
      m[*ita1] = m[*ita1] + -m[*ita2];
    }
  }
  cout << ans << endl;
}
