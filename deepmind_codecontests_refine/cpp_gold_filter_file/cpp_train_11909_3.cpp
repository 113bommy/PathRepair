#include <bits/stdc++.h>
using namespace std;
set<int> a;
set<int> b;
set<int> c;
vector<int> aa, bb, cc;
int n;
void solve() {
  if (c.size() == n) {
    cout << "----------xxxxxxxx----------" << '\n';
    for (int i = 0; i < (int)(n); i++) {
      cout << aa[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < (int)(n); i++) {
      cout << bb[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < (int)(n); i++) {
      cout << cc[i] << " ";
    }
    cout << '\n';
  }
  if (a.size() == n || b.size() == n) return;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(n); j++) {
      if ((i + j) % n == c.size() && a.count(i) == 0 && b.count(j) == 0) {
        a.insert(i);
        b.insert(j);
        c.insert((i + j) % n);
        aa.push_back(i);
        bb.push_back(j);
        cc.push_back((i + j) % n);
        solve();
        aa.pop_back();
        bb.pop_back();
        cc.pop_back();
        a.erase(i);
        b.erase(j);
        c.erase((i + j) % n);
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n % 2 == 0) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < (int)(n); i++) {
    cout << n - i - 1 << " ";
  }
  cout << '\n';
  for (int i = 0; i < (int)(n); i++) {
    cout << (1 + i * 2) % n << " ";
  }
  cout << '\n';
  for (int i = 0; i < (int)(n); i++) {
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
