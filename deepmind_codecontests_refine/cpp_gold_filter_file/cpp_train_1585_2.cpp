#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i;
  char s[5000];
  cin >> t;
  while (t--) {
    cin >> n >> s;
    vector<int> v;
    for (i = strlen(s) - 1; i >= 0; i--) {
      if ((s[i] - '0') % 2 != 0) v.push_back(s[i] - '0');
    }
    if (v.size() > 1)
      cout << v[1] << v[0] << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
