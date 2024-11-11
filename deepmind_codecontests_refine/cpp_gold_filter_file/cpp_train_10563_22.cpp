#include <bits/stdc++.h>
using namespace std;
int main() {
  string temp;
  vector<string> fla, sla, text;
  long long n, m, i = 0, j = 0;
  cin >> n >> m;
  for (; i < m; i++) {
    cin >> temp;
    fla.push_back(temp);
    cin >> temp;
    sla.push_back(temp);
  }
  for (; j < n; j++) {
    cin >> temp;
    text.push_back(temp);
  }
  for (long long kk = 0; kk < text.size(); kk++) {
    temp = text[kk];
    for (long long zz = 0; zz < fla.size(); zz++) {
      if ((temp == fla[zz]) || (temp == sla[zz])) {
        if (fla[zz].size() <= sla[zz].size()) {
          text[kk] = fla[zz];
          break;
        } else {
          text[kk] = sla[zz];
          break;
        }
      }
    }
  }
  for (long long ii = 0; ii < text.size() - 1; ii++) cout << text[ii] << " ";
  cout << text[text.size() - 1] << "\n";
  return 0;
}
