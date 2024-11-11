#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n;
  vector<pair<int, int> > a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(make_pair(x, -1));
  }
  cin >> q;
  vector<int> b(q, 0);
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      int p, x;
      cin >> p >> x;
      a[p - 1].first = x;
      a[p - 1].second = i;
    } else {
      int x;
      cin >> x;
      b[i] = x;
    }
  }
  int mx = 0;
  for (int i = q - 1; i >= 0; i--) {
    mx = max(b[i], mx);
    b[i] = mx;
  }
  for (int i = 0; i < n; i++) {
    int p = a[i].first;
    int x = a[i].second + 1;
    if (p < b[x]) p = b[x];
    cout << p << " ";
  }
}
