#include <bits/stdc++.h>
using namespace std;
template <class _t>
_t get(istream& in = cin) {
  _t x;
  in >> x;
  return x;
}
int n = get<int>(), maxe = -1, ls = 1000000000;
map<int, int> last;
int main() {
  for (int i = 0; i < n; i++) last[get<int>()] = i;
  for (auto p : last)
    if (p.second < ls) maxe = p.first, ls = p.second;
  cout << maxe << endl;
  return 0;
}
