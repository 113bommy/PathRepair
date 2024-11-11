#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  c_p_c();
  int x;
  cin >> x;
  while (x--) {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      v.push_back(e);
    }
    vector<int> hel(n + 1);
    for (int i = 2; i < n; i++) {
      if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
        hel[i] = 1;
      } else {
        hel[i] = 0;
      }
    }
    for (int i = 2; i <= n; i++) {
      hel[i] = hel[i] + hel[i - 1];
    }
    int res = 0;
    int left = 1;
    for (int i = 1; i <= n - k + 1; i++) {
      int d = hel[i + k - 2] - hel[i];
      if (d > res) {
        res = d;
        left = i;
      }
    }
    cout << res + 1 << " " << left;
    cout << endl;
  }
  return 0;
}
