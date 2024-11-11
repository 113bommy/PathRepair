#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int main() {
  cin >> n;
  vector<int> a(300000, 0);
  set<int> f, g;
  for (int i = 0; i < n; i++) {
    cin >> l;
    f.insert(l);
    a[l]++;
    if (a[l] > 2) return !(cout << "NO");
    if (a[l] == 2) g.insert(l);
  }
  cout << "YES\n";
  cout << f.size();
  while (f.size()) {
    cout << *f.begin() << ' ';
    f.erase(f.begin());
  }
  cout << '\n';
  cout << g.size() << '\n';
  while (g.size()) {
    cout << *g.rbegin() << ' ';
    g.erase(g.find(*g.rbegin()));
  }
}
