#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> s1(n + 1);
  vector<char> s2(n + 1);
  s1[0] = 'a' - 1;
  s2[0] = 'a' - 1;
  int p1 = 1;
  int p2 = 1;
  vector<bool> res(n);
  for (int i = 0; i < int(n); ++i) {
    if (s[i] >= s1[p1 - 1]) {
      s1[p1] = s[i];
      ++p1;
    } else {
      if (s[i] < s2[p2 - 1]) {
        cout << "NO";
        return 0;
      } else {
        s2[p2] = s[i];
        ++p2;
        res[i] = 1;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < int(n); ++i) cout << res[i];
}
