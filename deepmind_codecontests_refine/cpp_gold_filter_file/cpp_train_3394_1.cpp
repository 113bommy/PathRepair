#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, ca = 0, cb = 0, idx = -1, j, max = 0, z = 1, l, t = 0;
  cin >> n >> a;
  int ara[n];
  vector<int> p;
  vector<int> q(1000007);
  int i;
  for (i = 0; i < n; i++) {
    cin >> ara[i];
    if (ara[i] == a && z == 1) {
      ca++;
      idx = i;
      z = 0;
    } else if (z == 1) {
      p.push_back(ara[i]);
      q[ara[i]]++;
    }
  }
  if (idx == -1) {
    cout << ara[0];
    return 0;
  }
  l = p.size();
  if (l == 0) {
    cout << -1;
    return 0;
  } else {
    for (i = idx + 1; i < n; i++) {
      if (q[ara[i]] != 0) q[ara[i]]++;
      if (ara[i] == a) {
        ca++;
        for (j = 0; j < l; j++) {
          if (q[p[j]] < ca)
            q[p[j]] = 0;
          else
            t = 1;
        }
        if (t == 0) {
          cout << -1;
          return 0;
        }
        t = 0;
      }
    }
  }
  for (i = 0; i < l; i++)
    if (q[p[i]] != 0) {
      cout << p[i];
      break;
    }
  return 0;
}
