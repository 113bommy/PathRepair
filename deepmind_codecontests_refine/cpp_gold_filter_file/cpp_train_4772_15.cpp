#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());
  cout << (s < t ? "Yes" : "No") << endl;
  return 0;
}