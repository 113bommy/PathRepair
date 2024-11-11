#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string x;
  cin >> x;
  int n = x.length();
  set<string> my;
  my.insert(x);
  for (int i = 0; i < n; ++i) {
    x = x.substr(n - 1) + x.substr(0, n - 1);
    my.insert(x);
  }
  cout << x.size();
}
