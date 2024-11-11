#include <bits/stdc++.h>
using namespace std;
int fhi[1 << 18];
int fps[26];
vector<int> bps[26];
int main() {
  memset(fhi, -1, sizeof fhi);
  string a, b;
  cin >> a >> b;
  int bp = 0;
  for (int i = 0; i < (int)(a.length()); i++) {
    if (bp < (int)(b.length()) && a[i] == b[bp]) {
      fps[a[i] - 'a'] = bp;
      ++bp;
    }
    fhi[i] = fps[a[i] - 'a'];
  }
  bp = (int)(b.length()) - 1;
  bool good = 1;
  for (int i = (int)(a.length()) - 1; i >= 0; i--) {
    if (bp >= 0 && a[i] == b[bp]) {
      bps[a[i] - 'a'].push_back(bp);
      --bp;
    }
    int lo = 0, hi = (int)(bps[a[i] - 'a'].size()) - 1;
    bool found = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (bps[a[i] - 'a'][mid] > fhi[i])
        lo = mid + 1;
      else if (bps[a[i] - 'a'][mid] < fhi[i])
        hi = mid - 1;
      else {
        found = 1;
        break;
      }
    }
    good &= found;
  }
  cout << (good ? "Yes" : "No") << '\n';
  return 0;
}
