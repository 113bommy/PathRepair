#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  vector<char> c;
  vector<long long> v;
  for (long long i = 0; i < s.length(); i++) {
    if (i == 0) {
      c.push_back(s[i]);
      v.push_back(1);
    } else {
      for (long long j = 0; j < c.size(); j++) {
        if (s[i] == c[j]) {
          v[j]++;
          break;
        }
        if (j == c.size() - 1) {
          c.push_back(s[i]);
          v.push_back(1);
        }
      }
    }
    if (c.size() > 4) {
      cout << "No";
      return 0;
    }
  }
  if ((c.size() == 2 && v[0] > 1 && v[1] > 1) || c.size() == 4 ||
      (c.size() == 3 && (v[0] > 1 || v[1] > 1 || v[2] > 1)))
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
