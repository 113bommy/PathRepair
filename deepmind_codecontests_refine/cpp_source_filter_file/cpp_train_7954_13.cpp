#include <bits/stdc++.h>
using namespace std;
string s;
int mid, i, cnt = 0;
int main() {
  cin >> s;
  mid = s.find("^");
  for (int i = 0; i < ((int)s.size()); ++i)
    if (s[i] >= '1' && s[i] <= '9') cnt += (s[i] - '0') * (i - mid);
  if (cnt == 0) cout << "balance" << endl;
  if (cnt < 0) cout << "left" << endl;
  if (cnt > 0) cout << "right" << endl;
  return 0;
}
