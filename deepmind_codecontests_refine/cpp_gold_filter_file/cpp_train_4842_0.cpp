#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto& x : v) cin >> x;
  int m = 0;
  for (int i = 0; i < 26; ++i)
    for (int j = i + 1; j < 26; ++j) {
      auto valid = [&](const string& s) {
        for (auto c : s)
          if ((c != 'a' + i) && (c != 'a' + j)) return false;
        return true;
      };
      int s = 0;
      for (auto& x : v)
        if (valid(x)) s += x.size();
      m = max(m, s);
    }
  cout << m << endl;
  return 0;
}
