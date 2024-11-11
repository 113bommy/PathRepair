#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s;
  set<int> l[26];
  for (int i = 0; i < k; i++) l[s[i] - 'a'].insert(i);
  for (int i = 0; i < 26; i++) {
    l[i].insert(inf);
    l[i].insert(-inf);
  }
  while (n--) {
    int cnt = 0, tmp, ll;
    set<int>::iterator lhs, rhs;
    cin >> t;
    for (int i = 0; i < t.size(); i++) {
      tmp = t[i] - 'a';
      lhs = rhs = l[tmp].upper_bound(i);
      lhs--;
      ll = min(*rhs - i, i - *lhs);
      if (ll < inf / 2)
        cnt += ll;
      else
        cnt += t.size();
    }
    cout << cnt << endl;
  }
  return 0;
}
