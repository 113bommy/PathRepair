#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  char c[5] = {'a', 'e', 'i', 'o', 'u'};
  int r[4] = {0};
  int flag = 0;
  for (int i = 0; i < n; i++) {
    vector<string> v;
    for (int i = 0; i < 4; i++) {
      string str, p = "";
      cin >> str;
      int ctr = 0;
      for (int l = str.size() - 1; l >= 0 && flag == 0; l--) {
        p = p + str[l];
        if (str[l] == c[0] || str[l] == c[1] || str[i] == c[2] ||
            str[l] == c[3] || str[l] == c[4]) {
          ctr++;
          if (ctr == k) {
            v.push_back(p);
            break;
          }
        }
      }
      if (ctr != k) {
        flag = 1;
      }
    }
    if (flag == 0 && v.size() == 4) {
      if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3])
        r[3]++;
      else if (v[0] == v[1] && v[2] == v[3])
        r[0]++;
      else if (v[0] == v[2] && v[1] == v[3])
        r[1]++;
      else if (v[0] == v[3] && v[1] == v[2])
        r[2]++;
      else
        flag = 1;
    }
  }
  if (flag == 1)
    cout << "NO" << endl;
  else if (r[0] == 0 && r[1] == 0 && r[2] != 0)
    cout << "abba" << endl;
  else if (r[0] == 0 && r[1] != 0 && r[2] == 0)
    cout << "abab" << endl;
  else if (r[0] != 0 && r[1] == 0 && r[2] == 0)
    cout << "aabb" << endl;
  else if (r[0] == 0 && r[1] == 0 && r[2] == 0 && r[3] != 0)
    cout << "aaaa" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
