#include <bits/stdc++.h>
using namespace std;
int gr[10010000][2], b[10010000], a[300100], p2[31];
int new_ver = 1, pol = 0, n, x, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  p2[0] = 1;
  for (int i = 1; i <= 30; i++) p2[i] = 2 * p2[i - 1];
  for (int i = 0; i < 10010000; i++) gr[i][0] = -1, gr[i][1] = -1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    vector<int> d;
    d.clear();
    for (int j = 0; j <= 30; j++) {
      d.push_back(x % 2);
      x /= 2;
    }
    pol = 0;
    b[pol]++;
    for (int j = 30; j >= 0; j--) {
      if (gr[pol][d[j]] == -1) {
        gr[pol][d[j]] = new_ver;
        pol = new_ver++;
        b[pol]++;
      } else {
        pol = gr[pol][d[j]];
        b[pol]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    vector<int> d;
    d.clear();
    for (int j = 0; j <= 30; j++) d.push_back(a[i] % 2), a[i] /= 2;
    pol = 0;
    ans = 0;
    for (int j = 30; j >= 0; j--) {
      if (gr[pol][d[j]] != -1) {
        int t = gr[pol][d[j]];
        b[t]--;
        if (b[t] == 0) {
          gr[pol][d[j]] = -1;
        }
        pol = t;
      } else {
        pol = gr[pol][1 - d[j]];
        b[pol]--;
        ans += p2[j];
      }
    }
    cout << ans << " ";
  }
}
