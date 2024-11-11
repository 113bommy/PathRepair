#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, s3;
  int cnt1 = 0, cnt2 = 0;
  int res = 0;
  cin >> s1;
  s1 += "            ";
  for (int i = 0; i < s1.size() - 8; i++) {
    if (s1.substr(i, 5) == "heavy") cnt1++;
    if (s1.substr(i, 5) == "metal") res += cnt1;
  }
  cout << res << endl;
}
