#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] < s[i - 1]) {
      cout << "YES" << endl;
      cout << i << " " << i + 1 << endl;
      m++;
      i = s.size();
    }
  }
  if (m == 0) cout << "NO" << endl;
}
