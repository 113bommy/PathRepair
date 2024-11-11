#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1, -1);
  vector<pair<int, int> > q;
  vector<int> ts(n);
  for (int i = 0; i < k; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    ts[i] = t;
    q.push_back(make_pair(l, r));
    if (t == 1) {
      for (int j = l; j <= r; j++) {
        v[j] = 0;
      }
    }
  }
  vector<int> arr(n + 1, 0);
  arr[0] = n + 1;
  for (int i = 1; i <= n; i++) {
    arr[i] = arr[i - 1] + v[i];
  }
  for (int i = 0; i < k; i++) {
    if (ts[i] == 0) {
      if (is_sorted(arr.begin() + q[i].first, arr.begin() + q[i].second + 1)) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
}
