#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
string s;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  int n1 = 0, n0 = 0;
  for (int i = int((s).size()) - 1; i >= 0; --i) {
    if (s[i] == '1') {
      if (n1 >= n0)
        s[i] = '0';
      else
        n1++;
    } else
      n0++;
  }
  cout << s << endl;
  return 0;
}
