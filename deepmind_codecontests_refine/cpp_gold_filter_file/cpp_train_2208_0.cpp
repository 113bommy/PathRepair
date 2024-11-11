#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
int main() {
  long long int n, i, j, k, res, fl;
  string ss, tt;
  long long int t;
  cin >> t;
  while (t--) {
    cin >> ss;
    reverse(ss.begin(), ss.end());
    ss.push_back('#');
    ss.push_back('#');
    reverse(ss.begin(), ss.end());
    long long int cc = 0;
    for (i = 0; i <= ss.size() - 3; i++) {
      if (ss[i] == 'o' && ss[i + 1] == 'n' && ss[i + 2] == 'e') {
        cc++;
      } else if (ss[i] == 't' && ss[i + 1] == 'w' && ss[i + 2] == 'o')
        cc++;
    }
    if (cc == 0) {
      cout << 0 << '\n';
      cout << '\n';
    } else {
      long long int co = 0;
      for (i = ss.size() - 1; i >= 4; i--) {
        if (ss[i] == 'e' && ss[i - 1] == 'n' && ss[i - 2] == 'o') {
          if (ss[i - 3] == 'w' && ss[i - 4] == 't') {
            co++;
            ss[i - 2] = '*';
          } else {
            co++;
            ss[i - 1] = '*';
          }
        }
      }
      for (i = ss.size() - 1; i >= 4; i--) {
        if (ss[i] == 'o' && ss[i - 1] == 'w' && ss[i - 2] == 't') {
          co++;
          ss[i - 1] = '*';
        }
      }
      for (i = 0; i < ss.size(); i++) {
        if (ss[i] == '*') {
          v.push_back(i - 1);
        }
      }
      cout << co << '\n';
      for (i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
      cout << '\n';
      v.clear();
    }
  }
  return 0;
}
