#include <bits/stdc++.h>
using namespace std;
int main(void) {
  vector<int> z[26];
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.size(); ++i) z[a[i] - 'a'].push_back(i);
  bool ok = true;
  for (int i = 0; i < b.size(); ++i) {
    if (z[b[i] - 'a'].size() == 0) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    int cnt = 1, cur = -1;
    for (int i = 0; i < b.size(); ++i) {
      vector<int> &tmp = z[b[i] - 'a'];
      vector<int>::iterator iter = upper_bound(tmp.begin(), tmp.end(), cur);
      if (iter == tmp.end()) {
        ++cnt;
        cur = tmp[0];
      } else {
        cur = *iter;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
