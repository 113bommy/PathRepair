#include <bits/stdc++.h>
using namespace std;
set<int> w;
set<int> h;
multiset<int> wlen;
multiset<int> hlen;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  char a;
  int pos;
  h.insert(0);
  h.insert(m);
  hlen.insert(m);
  w.insert(0);
  w.insert(n);
  wlen.insert(n);
  int hh = 1, ww = 1;
  for (int i = 0; i < k; i++) {
    cin >> a >> pos;
    if (a == 'H') {
      set<int>::iterator it = h.upper_bound(pos);
      int bigger = *it;
      int smaller = *(--it);
      hlen.erase(hlen.lower_bound(bigger - smaller));
      hlen.insert(bigger - pos);
      hlen.insert(pos - smaller);
      h.insert(pos);
    }
    if (a == 'V') {
      set<int>::iterator it = w.upper_bound(pos);
      int bigger = *it;
      int smaller = *(--it);
      wlen.erase(wlen.lower_bound(bigger - smaller));
      wlen.insert(bigger - pos);
      wlen.insert(pos - smaller);
      w.insert(pos);
    }
    set<int>::iterator itt1 = wlen.end();
    set<int>::iterator itt2 = hlen.end();
    itt1--;
    itt2--;
    cout << (*itt1) * (*itt2) << endl;
  }
  return 0;
}
