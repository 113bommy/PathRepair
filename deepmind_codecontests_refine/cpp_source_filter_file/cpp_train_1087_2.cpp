#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int X = 1e4;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> neg, pos, zero, res;
  while (n--) {
    int a;
    cin >> a;
    if (a < 0)
      neg.push_back(a);
    else if (a > 0)
      pos.push_back(a);
    else
      zero.push_back(a);
  }
  if (pos.size()) {
    for (int i = 0; i < pos.size(); i++) res.push_back(pos[i]);
  }
  sort(neg.rbegin(), neg.rend());
  if (neg.size() > 1) {
    if (neg.size() % 2) neg.pop_back();
    for (int i = 0; i < neg.size(); i++) res.push_back(neg[i]);
  }
  if (!res.size()) {
    if (zero.size())
      res.push_back(0);
    else
      res.push_back(neg[neg.size() - 1]);
  }
  for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
}
