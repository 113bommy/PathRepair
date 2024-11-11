#include <bits/stdc++.h>
using namespace std;
class classcomp {
 public:
  bool operator()(const int& l, const int& r) const { return l < r; }
};
int main() {
  int n, k, last;
  string s;
  cin >> n >> k;
  cin >> s;
  last = 0;
  int p = s.size();
  if ((p - 1) - last <= k) {
    cout << "YES";
    return 0;
  }
  for (int i = 1; i < s.size() - 1; ++i) {
    if (s[i] == '.') {
      if (i - last <= k) {
        if ((p - 1) - i <= k) {
          cout << "YES";
          return 0;
        } else
          last = i;
      }
    }
  }
  cout << "NO";
}
