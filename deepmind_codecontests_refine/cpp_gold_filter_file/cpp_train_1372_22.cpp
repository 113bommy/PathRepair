#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    int arr[n], visi[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      visi[i] = 0;
    }
    int q;
    cin >> q;
    int i = 0, j, mx;
    vector<pair<int, pair<int, int>>> fir;
    vector<pair<int, int>> sec;
    while (q--) {
      int x, y;
      cin >> x >> y;
      if (x == 1) {
        --y;
        int z;
        cin >> z;
        fir.push_back({++i, {y, z}});
      } else {
        sec.push_back({++i, y});
      }
    }
    i = fir.size() - 1, j = sec.size() - 1, mx = 0;
    while (i >= 0 && j >= 0) {
      int idxf = fir[i].first, idxs = sec[j].first;
      if (idxf > idxs) {
        if (visi[fir[i].second.first] == 0) {
          visi[fir[i].second.first] = 1;
          arr[fir[i].second.first] = max(fir[i].second.second, mx);
        }
        --i;
      } else {
        mx = max(mx, sec[j].second);
        --j;
      }
    }
    while (i >= 0) {
      if (visi[fir[i].second.first] == 0) {
        visi[fir[i].second.first] = 1;
        arr[fir[i].second.first] = max(mx, fir[i].second.second);
      }
      --i;
    }
    while (j >= 0) {
      mx = max(mx, sec[j].second);
      --j;
    }
    for (int i = 0; i < n; ++i) {
      if (visi[i] == 0) arr[i] = max(arr[i], mx);
      cout << arr[i] << " \n"[i == n];
    }
  }
  return 0;
}
