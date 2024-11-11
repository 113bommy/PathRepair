#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> bm;
  vector<int> bf;
  vector<int> am;
  vector<int> af;
  int p = -1;
  int c = 0;
  for (auto x : b) {
    if (x == p)
      c++;
    else {
      if (p != -1) {
        bm.push_back(p);
        bf.push_back(c);
      }
      p = x;
      c = 1;
    }
  }
  bm.push_back(p);
  bf.push_back(c);
  p = -1;
  c = 0;
  for (auto x : a) {
    if (x == p)
      c++;
    else {
      if (p != -1) {
        am.push_back(p);
        af.push_back(c);
      }
      p = x;
      c = 1;
    }
  }
  am.push_back(p);
  af.push_back(c);
  int l = bm.size();
  int ans = -1;
  for (int i = 0; i < l; i++) {
    int s = 1;
    int k = (bm[i] - am[0] + m) % m;
    for (int j = 0; j < l; j++) {
      if ((am[j] + k) % m != bm[(i + j) % l] || af[j] != bf[(i + j) % l]) {
        s = 0;
        break;
      }
    }
    if (s == 1) {
      ans = k;
      break;
    }
  }
  cout << ans << "\n";
}
