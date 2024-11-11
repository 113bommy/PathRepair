#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    string str;
    cin >> str;
    string res = "";
    int n = str.size();
    if (n < 2) {
      cout << str << endl;
    } else {
      for (int i = 0; i < n; i++) {
        if (i < n - 1 && str[i] == str[i + 1]) {
          i++;
          continue;
        } else {
          res += str[i];
        }
      }
      sort(res.begin(), res.end());
      map<char, int> my_map;
      map<char, int>::iterator it;
      for (int i = 0; i < res.size(); i++) {
        my_map[str[i]]++;
      }
      string re = "";
      for (it = my_map.begin(); it != my_map.end(); it++) {
        re += it->first;
      }
      sort(re.begin(), re.end());
      cout << re << endl;
    }
  }
  return 0;
}
