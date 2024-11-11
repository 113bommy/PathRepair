#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  string s;
  for (i = 1; s.size() < 1000; i++) {
    s = s + to_string(i);
  }
  cout << s[n - 1] << endl;
  return 0;
}
