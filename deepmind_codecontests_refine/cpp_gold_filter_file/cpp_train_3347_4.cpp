#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
set<pair<int, int> > s;
int n, m;
int a[N], b[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    s.insert(make_pair(a[i], b[i]));
    s.insert(make_pair(b[i], a[i]));
  }
  bool ok = 0;
  for (int k = 1; k < n; k++) {
    bool tmp = 1;
    if (n % k == 0) {
      for (int i = 0; i < m; i++) {
        int A = a[i], B = b[i];
        int nA = (a[i] + k) % n, nB = (b[i] + k) % n;
        if (!s.count(make_pair(nA, nB))) tmp = 0;
      }
      ok |= tmp;
    }
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
