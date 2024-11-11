#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<char> v;
  if (s.find('F') == string::npos) {
    cout << "0" << endl;
    return 0;
  }
  if (s.find('M') == string::npos) {
    cout << "0" << endl;
    return 0;
  }
  int firstmen = 0x3f3f3f3f, lastf = -1;
  int ct1 = 0, ct2 = 0;
  long long ans = 0;
  for (int i = (0); i < (s.size()); ++i) {
    if (s[i] == 'M') {
      firstmen = min(firstmen, i);
      ct1++;
      ct2 = max(ct2 - 1, 0);
    }
    if (s[i] == 'F') {
      lastf = i;
      ans = max(ans, (long long)ct1 + ct2);
      ++ct2;
    }
  }
  if (firstmen > lastf) {
    cout << "0" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
