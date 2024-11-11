#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long flag = 0;
  string str;
  cin >> str;
  string s = str;
  vector<long long> vec;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] == 'B') {
      s[i] = 'W';
      if (s[i + 1] == 'W')
        s[i + 1] = 'B';
      else
        s[i + 1] = 'W';
      vec.push_back(i + 1);
    }
  }
  if (s[n - 1] != 'W') {
    for (long long i = n - 1; i > 0; i--) {
      if (s[i] == 'W') {
        s[i] = 'B';
        if (s[i - 1] == 'W')
          s[i - 1] = 'B';
        else
          s[i - 1] = 'W';
        vec.push_back(i);
      }
    }
    if (s[0] == 'W') flag = 1;
  }
  if (flag == 1)
    cout << "-1";
  else {
    cout << vec.size() << endl;
    for (long long i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  }
}
