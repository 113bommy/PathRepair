#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int idx = str.length();
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'M') {
      idx = i;
      break;
    }
  }
  int ans = 0;
  int sum = 0;
  int last = 0;
  int cnt = 0;
  for (int i = idx; i < str.length(); i++) {
    if (str[i] == 'M')
      sum += 1;
    else {
      int val = i - cnt;
      if (last >= val) {
        last = last + 1;
      } else
        last = val;
      cnt += 1;
    }
  }
  cout << last << endl;
  return 0;
}
