#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
void solve() {
  long long int i, j, k, pa, push_back, a[3][3], b[3][3];
  cin >> k >> pa >> push_back;
  pa--;
  push_back--;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> b[i][j];
      b[i][j]--;
    }
  }
  map<pair<long long int, long long int>, long long int> m;
  m[{2, 1}] = 1;
  m[{1, 0}] = 1;
  m[{0, 2}] = 1;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (m[{i, j}] == 0) {
        m[{i, j}] = -1;
      }
    }
    m[{i, i}] = 0;
  }
  vector<pair<long long int, long long int> > v, bef, aft;
  v.push_back({pa, push_back});
  long long int aw = 0, bw = 0, paw = 0, pbw = 0;
  while (1) {
    long long int ca = a[pa][push_back];
    long long int cb = b[pa][push_back];
    long long int ind = -1;
    for (i = 0; i < v.size(); i++) {
      if (v[i].first == ca && v[i].second == cb) {
        ind = i;
        break;
      }
    }
    if (ind != -1) {
      for (i = 0; i < ind; i++) {
        bef.push_back(v[i]);
      }
      for (i = ind; i < v.size(); i++) {
        aft.push_back(v[i]);
      }
      break;
    }
    v.push_back({ca, cb});
    pa = ca;
    push_back = cb;
  }
  long long int rem = k;
  long long int x = min(rem, (long long int)bef.size());
  rem -= x;
  for (i = 0; i < x; i++) {
    if (m[bef[i]] == 1) {
      aw++;
    } else if (m[bef[i]] == -1) {
      bw++;
    }
  }
  for (i = 0; i < aft.size(); i++) {
    if (m[aft[i]] == 1) {
      paw++;
    } else if (m[aft[i]] == -1) {
      pbw++;
    }
  }
  long long int y = rem / aft.size();
  aw += y * paw;
  bw += y * pbw;
  rem -= y * aft.size();
  i = 0;
  while (rem--) {
    if (m[bef[i]] == 1) {
      aw++;
    } else if (m[bef[i]] == -1) {
      bw++;
    }
    i++;
  }
  cout << aw << " " << bw;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
