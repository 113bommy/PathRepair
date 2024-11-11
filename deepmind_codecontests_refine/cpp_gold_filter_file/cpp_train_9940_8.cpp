#include <bits/stdc++.h>
using namespace std;
int main() {
  long long w, h, n;
  cin >> w >> h >> n;
  set<int> hv, wv;
  hv.insert(0);
  wv.insert(0);
  hv.insert(h);
  wv.insert(w);
  multiset<long long> hd, wd;
  hd.insert(h);
  wd.insert(w);
  while (n--) {
    char c;
    cin >> c;
    int x;
    cin >> x;
    if (c == 'V') {
      wv.insert(x);
      auto h = wv.lower_bound(x);
      h++;
      auto after = h;
      h--, h--;
      auto before = h;
      h++;
      wd.erase(wd.lower_bound(*after - *before));
      wd.insert(*after - *h);
      wd.insert(*h - *before);
      cout << (*wd.rbegin()) * (*hd.rbegin()) << '\n';
    } else {
      hv.insert(x);
      auto h = hv.lower_bound(x);
      h++;
      auto after = h;
      h--, h--;
      auto before = h;
      h++;
      hd.erase(hd.lower_bound(*after - *before));
      hd.insert(*after - *h);
      hd.insert(*h - *before);
      cout << (*wd.rbegin()) * (*hd.rbegin()) << '\n';
    }
  }
}
