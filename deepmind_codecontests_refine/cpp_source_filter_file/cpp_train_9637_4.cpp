#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10000 + 10, mod = 1000000007;
int dig[20];
string t[100000];
pair<int, int> get(string s) {
  cout << s << endl;
  int x, y;
  cin >> x >> y;
  if (x == 4) exit(0);
  return {x, y};
}
bool ch(string s) {
  int d[20] = {};
  for (int i = 0; i < 4; i++) d[(s[i] - '0')]++;
  for (int i = 0; i < 10; i++) {
    if (d[i] != dig[i]) return false;
  }
  return true;
}
string make(int x) {
  string s = "";
  for (int i = 0; i < 4; i++) {
    s += ('0' + i);
    x /= 10;
  }
  return s;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  for (int i = 0; i < 10; i++) {
    string s = "";
    for (int j = 0; j < 4; j++) s += ('0' + i);
    dig[i] = get(s).first;
  }
  for (int i = 0; i <= 9999; i++) {
    if (ch(make(i))) {
      if (get(make(i)).first == 4) {
        cout << make(i) << endl;
        return 0;
      }
    }
  }
  return 0;
}
