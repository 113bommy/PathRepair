#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  vector<string> res;
  int ls, n0 = 0, n1 = 0, nq = 0;
  cin >> s;
  ls = s.length() - 1;
  for (int i = 0; i <= ls; i++)
    if (s[i] == '0')
      n0++;
    else if (s[i] == '1')
      n1++;
    else
      nq++;
  if (n0 + nq > n1) res.push_back("00");
  if (n1 + nq > n0 + 1) res.push_back("11");
  if (((ls + 1) % 2 == 1 && n0 <= (ls + 1) && n1 <= (ls + 1) / 2 + 1) ||
      ((ls + 1) % 2 == 0 && n0 <= (ls + 1) && n1 <= (ls + 1) / 2)) {
    int pos0 = 0, pos1 = 0, nt0 = n0, nt1 = n1;
    for (int i = 0; i <= ls; i++) {
      if (s[i] == '0') pos0 = i;
      if (s[i] == '1') pos1 = i;
      if (s[i] == '?') {
        if (nt1 <= ls / 2) {
          pos1 = i;
          nt1++;
        } else {
          pos0 = i;
          nt0++;
        }
      }
    }
    if (pos0 > pos1) res.push_back("10");
    pos0 = 0;
    pos1 = 0, nt0 = n0, nt1 = n1;
    for (int i = 0; i <= ls; i++) {
      if (s[i] == '0') pos0 = i;
      if (s[i] == '1') pos1 = i;
      if (s[i] == '?') {
        if (nt0 < (ls + 1) / 2) {
          pos0 = i;
          nt0++;
        } else {
          pos1 = i;
          nt1++;
        }
      }
    }
    if (pos1 > pos0) res.push_back("01");
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
