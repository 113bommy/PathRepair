#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    string s;
    cin >> s;
    int res = s.length(), cur;
    vector<long long> a;
    cur = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-')
        cur--;
      else
        cur++;
      if (cur < 0)
        if (a.size() == 0 || cur < a[a.size() - 1]) {
          a.push_back(cur);
          res += i + 1;
        }
    }
    cout << res << endl;
  }
}
