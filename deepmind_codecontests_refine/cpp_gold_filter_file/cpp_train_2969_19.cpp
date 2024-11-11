#include <bits/stdc++.h>
using namespace std;
class new_year {
  long long x, type;

 public:
  void read() {
    string s1, s;
    cin >> x;
    cin >> s1 >> s;
    if (s[s.length() - 1] == 'k')
      type = 1;
    else
      type = 2;
  }
  int ans() {
    if (type == 2) {
      if (x == 31)
        return 7;
      else if (x == 30)
        return 11;
      else
        return 12;
    }
    if (type == 1) {
      if (x == 5 || x == 6)
        return 53;
      else
        return 52;
    }
  }
};
int main() {
  new_year ne;
  ne.read();
  cout << ne.ans();
  return 0;
}
