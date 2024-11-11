#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int w, o;
    cin >> w >> o;
    int h1, h2, v1, v2, d1, d2, d3, d4;
    cin >> h1;
    vector<int> h(h1);
    for (int i = 0; i < h1; i++) {
      cin >> h[i];
    }
    d1 = h.back() - h.front();
    cin >> h2;
    vector<int> hh(h2);
    for (int i = 0; i < h2; i++) {
      cin >> hh[i];
    }
    d2 = hh.back() - hh.front();
    cin >> v1;
    vector<int> v(v1);
    for (int i = 0; i < v1; i++) {
      cin >> v[i];
    }
    d3 = v.back() - v.front();
    cin >> v2;
    vector<int> vv(v2);
    for (int i = 0; i < v2; i++) {
      cin >> vv[i];
    }
    d4 = vv.back() - vv.front();
    long long ans1 = max(d1, d2) * o, ans2 = max(d3, d4) * w;
    cout << max(ans1, ans2) << "\n";
  }
  return 0;
}
