#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> comp;
  int n, m, x, y, sum = 0, coun = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    sum += x;
    comp.push_back(x - y);
  }
  sort(comp.begin(), comp.end());
  while (sum > m) {
    sum -= comp.back();
    coun++;
    comp.pop_back();
    if (comp.empty()) break;
  }
  cout << (sum > m ? -1 : coun);
  return 0;
}
