#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  for (int i = a; i < b + 1; i++) {
    string s = to_string(i);
    if (s.size() == (set<char>(s.begin(), s.end())).size()) {
      cout << i;
      exit(0);
    }
  }
  cout << -1;
  return 0;
}
