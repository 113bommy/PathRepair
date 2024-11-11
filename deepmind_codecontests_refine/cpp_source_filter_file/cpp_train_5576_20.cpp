#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  string s;
  cin >> n >> t >> s;
  string res = "0" + s;
  int i = 0;
  while (i < (int)res.size() && res[i++] != '.')
    ;
  int dec = i - 1;
  while (i < (int)res.size() && res[i] <= '4') ++i;
  if (i == (int)res.size()) {
    cout << "b" << s << endl;
    return 0;
  }
  for (int j = i; t > 0 && j >= dec; --j) {
    if (res[j] > '4') {
      res[j] = '\0';
      --j;
      while (res[j] == '9') {
        res[j] = '0';
        --j;
      }
      if (res[j] != '.')
        res[j] += 1;
      else {
        --j;
        while (res[j] == '9') {
          res[j] = '0';
          --j;
        }
        res[j] += 1;
      }
      --t;
      ++j;
    }
  }
  if (res[0] == '0') res = res.substr(1);
  i = 0;
  for (int k = 0; k < (int)res.size(); ++k)
    if (res[k] == '\0') res = res.substr(0, k);
  if (res[res.size() - 1] == '.') res = res.substr(0, res.size() - 1);
  cout << res << endl;
}
