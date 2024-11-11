#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15);
  if (argc == 2 && atoi(argv[1]) == 123456789)
    freopen("d:\\code\\cpp\\contests\\stdin", "r", stdin);
  int T;
  cin >> T;
  for (int(t) = 0; (t) < (T); (t)++) {
    int n, x, m;
    cin >> n >> x >> m;
    vector<pair<int, int> > a(m);
    for (int(i) = 0; (i) < (m); (i)++) cin >> a[i].first >> a[i].second;
    int l = -1, r = -1;
    for (int(i) = 0; (i) < (m); (i)++) {
      if (l == -1 && a[i].first <= x && x <= a[i].second) {
        l = a[i].first;
        r = a[i].second;
      } else {
        if (max(l, a[i].first) <= min(r, a[i].second)) {
          l = min(l, a[i].first);
          r = max(r, a[i].second);
        }
      }
    }
    if (l == -1)
      cout << 0 << endl;
    else {
      cout << r - l + 1 << endl;
    }
  }
  if (argc == 2 && atoi(argv[1]) == 123456789)
    cout << clock() * 1.0 / CLOCKS_PER_SEC << " sec\n";
  return 0;
}
