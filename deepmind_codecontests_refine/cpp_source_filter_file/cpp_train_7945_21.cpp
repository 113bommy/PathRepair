#include <bits/stdc++.h>
using namespace std;
bool isCentered(const int &value, set<int> &s) {
  auto last = s.end();
  --last;
  return (value != *(s.begin()) && value != *last);
}
int main() {
  map<int, set<int>> xMap;
  map<int, set<int>> yMap;
  int n;
  cin >> n;
  map<int, set<int>>::iterator it;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    it = xMap.find(x);
    if (it == xMap.end()) {
      set<int> s;
      s.insert(y);
      xMap.insert(pair<int, set<int>>(x, s));
    } else
      it->second.insert(y);
    it = yMap.find(y);
    if (it == yMap.end()) {
      set<int> s;
      s.insert(x);
      yMap.insert(pair<int, set<int>>(y, s));
    } else
      it->second.insert(x);
  }
  int centeredCount = 0;
  auto lastX = xMap.end();
  --lastX;
  auto lastY = yMap.end();
  --lastY;
  for (auto &p : xMap) {
    if (p == *(xMap.begin()) || p == *(lastX)) continue;
    auto ly = p.second.end();
    ++ly;
    for (const int &y : p.second) {
      if (y == *(p.second.end()) || y == *ly) continue;
      auto p2 = yMap.find(y);
      int x = p.first;
      if (isCentered(x, p2->second)) ++centeredCount;
    }
  }
  cout << centeredCount;
}
