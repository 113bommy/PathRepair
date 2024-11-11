#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string s = "";
  for (int i = 1; i <= 10000; i++) {
    s += to_string(i);
  }
  cout << s[k - 1] << endl;
  return 0;
}
