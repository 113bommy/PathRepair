#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
set<pair<int, int> > S;
int p[nmax];
int a[nmax];
bool l[nmax];
bool r[nmax];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  l[0] = r[0] = 1;
  S.insert(make_pair(a[1], 1));
  for (int i = 2; i <= n; i++) {
    auto itr = S.lower_bound(make_pair(a[i], i));
    int L, R;
    if (itr == S.begin()) {
      L = 0;
      R = itr->second;
    } else {
      if (itr == S.end()) {
        L = S.rbegin()->second;
        R = 0;
      } else {
        auto itl = itr;
        itl--;
        L = itl->second;
        R = itr->second;
      }
    }
    if (l[L]) {
      r[R] = true;
      p[i] = R;
    } else {
      l[L] = true;
      p[i] = L;
    }
    S.insert(make_pair(a[i], i));
  }
  for (int i = 2; i <= n; i++) {
    cout << a[p[i]] << ' ';
  }
  cout << '\n';
  return 0;
}
