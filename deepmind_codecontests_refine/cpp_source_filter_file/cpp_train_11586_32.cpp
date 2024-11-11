#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a;
  bool infg = false;
  bool infr = false;
  bool anyg = false;
  bool anyr = false;
  for (int i = (0); i < (int)(n); i++) {
    string s;
    cin >> s;
    int ir = -1, ig = -1, iv = -1;
    for (int j = (0); j < (int)(s.size()); j++) {
      if (s[j] == 'G') ig = j;
      if (s[j] == 'R') ir = j;
      if (s[j] == '-') iv = j;
    }
    if (ir == -1 && ig == -1) continue;
    if (iv == -1) continue;
    if (ir == -1) infg = true;
    if (ig == -1)
      infr = true;
    else
      a.push_back(abs(ir - ig));
    anyg |= (ig != -1);
    anyr |= (ir != -1);
  }
  bool lose = true;
  for (int b = (0); b < (int)(10); b++) {
    int sg = 0;
    for (int first = (0); first < (int)(a.size()); first++)
      sg += ((a[first] >> b) & 1);
    lose &= (sg % (k + 1)) == 0;
  }
  bool win = !lose;
  string ans;
  if (m == 1)
    ans = "Second";
  else if (anyg ^ anyr)
    ans = (anyg ? "First" : "Second");
  else if (infg && infr)
    ans = "Draw";
  else if (infg ^ infr)
    ans = (infg ? "First" : "Second");
  else
    ans = (win ? "First" : "Second");
  cout << ans << endl;
  return 0;
}
