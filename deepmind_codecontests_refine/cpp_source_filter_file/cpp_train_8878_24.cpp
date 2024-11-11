#include <bits/stdc++.h>
using namespace std;
void IS_LAM() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  IS_LAM();
  long long n, a, nn, x;
  string s, m;
  stringstream ss;
  cin >> s >> m;
  stringstream(s) >> n;
  stringstream(m) >> a;
  if (n < a) {
    cout << a;
    return 0;
  }
  while (s != m) {
    n++;
    ss << n;
    s = ss.str();
    ss.str("");
    string str = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '4' || s[i] == '7') str.push_back(s[i]);
    }
    if (str == m) {
      cout << s;
      return 0;
    }
  }
  return 0;
}
