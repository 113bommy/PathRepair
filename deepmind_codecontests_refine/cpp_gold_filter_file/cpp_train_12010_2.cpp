#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (; n--;) {
    int x;
    cin >> x;
    s.insert(x);
  }
  vector<int> v(s.begin(), s.end());
  if (v.size() < 2) return cout << "NO\n", 0;
  cout << v[1] << "\n";
  return 0;
}
