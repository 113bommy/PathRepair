#include <bits/stdc++.h>
using namespace std;
int main(void) {
  vector<int> can;
  int n, q, i, j, k, siz, res = 0;
  cin >> n >> q;
  string r[q];
  char l[q];
  for (i = 0; i < q; i++) {
    cin >> r[i] >> l[i];
    if (l[i] == 'a') can.push_back(i);
  }
  for (i = 0; i < can.size(); i++) {
    string str = r[can[i]];
    siz = str.size();
    vector<string> grid[n + 1];
    grid[2].push_back(str);
    while (siz < n) {
      for (j = 0; j < grid[siz].size(); j++) {
        str = grid[siz][j];
        for (k = 0; k < q; k++) {
          if (l[k] == str[0]) {
            string temp = r[0] + str;
            grid[siz + 1].push_back(temp);
          }
        }
      }
      siz++;
    }
    res += grid[n].size();
  }
  cout << res;
  return 0;
}
