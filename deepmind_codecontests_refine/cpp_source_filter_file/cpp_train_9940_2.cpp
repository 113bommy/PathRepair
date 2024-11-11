#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  multiset<int> height, width, maxw, maxh;
  width.insert(0);
  width.insert(w);
  height.insert(0);
  height.insert(h);
  maxw.insert(w);
  maxh.insert(h);
  char c;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> c >> x;
    if (c == 'H') {
      height.insert(x);
      auto it = height.find(x), is = height.find(x);
      it++;
      is--;
      auto ers = maxh.find(*it - *is);
      maxh.insert(*it - x);
      maxh.insert(x - *is);
      maxh.erase(ers);
    } else {
      width.insert(x);
      auto it = width.find(x), is = width.find(x);
      it++;
      is--;
      auto ers = maxw.find(*it - *is);
      maxw.insert(*it - x);
      maxw.insert(x - *is);
      maxw.erase(ers);
    }
    auto it = maxw.end(), is = maxh.end();
    it--;
    is--;
    cout << (*it) * (*is) << "\n";
  }
  return 0;
}
