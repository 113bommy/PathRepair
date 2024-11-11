#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
long double eps = 1e-9;
vector<char> m(11);
int findGreater(string s) {
  int index = -1;
  for (int i = 0; i < s.size(); i++) {
    if (m[s[i] - '0'] > s[i]) {
      index = i;
      break;
    }
  }
  return index;
}
int main() {
  string s;
  int n;
  cin >> n >> s;
  char val;
  for (int i = 0; i < 10; i++) {
    cin >> val;
    m[i + 1] = val;
  }
  for (int i = 0; i < s.size(); i++) {
    if (m[s[i] - '0'] > s[i]) {
      while (i < s.size() && m[s[i] - '0'] >= s[i]) {
        s[i] = m[s[i] - '0'];
        i++;
      }
      break;
    }
  }
  cout << s << '\n';
  return 0;
}
