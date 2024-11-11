#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while (cin >> s) {
    int val = 0, occ[2000] = {0};
    vector<int> vec;
    bool flag = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ',')
        vec.push_back(val), val = 0;
      else
        val = val * 10 + s[i] - '0';
    }
    vec.push_back(val);
    for (int i = 0; i < vec.size(); i++) occ[vec[i]]++;
    for (int i = 1; i <= 1000; i++) {
      if (occ[i]) {
        int j = i;
        while (j + 1 <= 1000 && occ[j + 1]) {
          j++;
        }
        if (flag) cout << ',';
        if (j - i > 1) {
          cout << i << '-' << j;
          i = j;
        } else
          cout << i;
        flag = 1;
      }
    }
  }
}
