#include <bits/stdc++.h>
using namespace std;
pair<int, int> d[100001];
int main() {
  int n, k, i, j, l, m, cnt, mi, kk;
  bool flag = true;
  set<pair<int, int> > se;
  cin >> n >> kk;
  vector<int> v[n];
  for (i = 0; i < n; i++) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d, d + n);
  flag = true;
  for (i = 1; i < n; i++) {
    if (d[i].first > d[i - 1].first + 1) {
      flag = false;
      break;
    }
  }
  if (d[0].first != 0 || (n > 1 && d[0].first == 0 && d[1].first == 0)) {
    flag = false;
  } else if (flag && n > 1) {
    vector<int> ans[n];
    v[0].push_back(d[0].second);
    m = d[0].second;
    mi = 0;
    j = 0;
    i = 1;
    cnt = 0;
    while (i < n && flag == true) {
      k = d[i].first;
      l = d[i].second;
      v[k].push_back(l);
      if (k == j) {
        while (ans[m].size() == kk) {
          if (v[j - 1].size() == mi + 1) {
            flag = false;
            break;
          } else {
            mi++;
            m = v[j - 1][mi];
          }
        }
      } else if (k == j + 1) {
        m = v[j][0];
        mi = 0;
        j = k;
        while (ans[m].size() == kk) {
          if (v[j].size() == mi + 1) {
            flag = false;
            break;
          } else {
            mi++;
            m = v[j][mi];
          }
        }
      }
      if (flag) {
        ans[m].push_back(l);
        ans[l].push_back(m);
        se.insert(pair<int, int>(l, m));
        v[k].push_back(l);
        cnt++;
      }
      i++;
    }
  }
  if (flag) {
    cout << cnt << endl;
    set<pair<int, int> >::iterator it;
    for (it = se.begin(); it != se.end(); it++) {
      cout << (*it).first + 1 << " " << (*it).second + 1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
