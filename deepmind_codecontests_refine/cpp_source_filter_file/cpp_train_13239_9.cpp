#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  cin >> t;
  int sol = (t.size() - 1) / 2;
  bool one = false;
  for (int i = 1; i < t.size(); i++) {
    if (t[i] == '1') {
      one = 1;
    }
  }
  if (one && (t.size() - 1) % 2 == 0) {
    sol++;
  }
  cout << sol << endl;
  return 0;
}
