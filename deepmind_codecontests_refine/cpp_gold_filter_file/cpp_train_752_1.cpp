#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int ar[N];
vector<int> ternary(int a) {
  vector<int> temp;
  while (a) {
    temp.push_back(a % 3);
    a /= 3;
  }
  return temp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, c;
  cin >> a >> c;
  vector<int> va = ternary(a), vc = ternary(c);
  while (va.size() != vc.size()) {
    if (va.size() > vc.size())
      vc.push_back(0);
    else
      va.push_back(0);
  }
  vector<int> vb;
  for (int i = 0; i < (int)va.size(); ++i) {
    vb.push_back((vc[i] - va[i] + 3) % 3);
  }
  int x = 0;
  for (int i = (int)vb.size() - 1; i >= 0; --i) {
    x *= 3;
    x += vb[i];
  }
  cout << x;
  return 0;
}
