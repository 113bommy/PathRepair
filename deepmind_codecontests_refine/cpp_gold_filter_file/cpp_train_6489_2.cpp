#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
string s;
int main() {
  int ret = -1;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    for (int j = i + 1; j < s.size(); j++) {
      int l1 = i, l2 = j - i, l3 = s.size() - j;
      if (l1 == 0 || l2 == 0 || l3 == 0) continue;
      if (l1 > 7 || l2 > 7 || l3 > 7) continue;
      string sa = s.substr(0, l1);
      string sb = s.substr(i, l2);
      string sc = s.substr(j, l3);
      int a = atoi(sa.c_str());
      int b = atoi(sb.c_str());
      int c = atoi(sc.c_str());
      bool flag = true;
      if (sa[0] == '0' && sa.size() > 1) {
        flag = false;
      }
      if (sb[0] == '0' && sb.size() > 1) {
        flag = false;
      }
      if (sc[0] == '0' && sc.size() > 1) {
        flag = false;
      }
      if (a > inf || b > inf || c > inf) {
        flag = false;
      }
      if (flag) ret = max(ret, a + b + c);
    }
  cout << ret << endl;
  return 0;
}
