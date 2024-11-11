#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  char ch;
  multiset<char> s;
  for (i = 0; i < n; ++i) {
    cin >> ch;
    s.insert(ch);
  }
  for (auto j : s) cout << j;
  cout << endl;
  return 0;
}
