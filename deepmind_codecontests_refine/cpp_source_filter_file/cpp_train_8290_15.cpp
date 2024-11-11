#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a;
  cin >> s;
  map<string, int> x;
  for (int i = 0; i < 10; ++i) {
    cin >> a;
    x[a] = i;
  }
  for (int i = 0; i < 10; ++i) {
    a = string(s.begin() + i * 8, s.begin() + i * 8 + 8);
    cout << x[a];
  }
  return 0;
}
