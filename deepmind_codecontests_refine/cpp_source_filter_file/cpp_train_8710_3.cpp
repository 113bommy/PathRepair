#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<pair<string, string> > v;
  string s[n];
  v.push_back(make_pair("purple", "Power"));
  v.push_back(make_pair("green", "Time"));
  v.push_back(make_pair("blue", "Space"));
  v.push_back(make_pair("orange", "Soul"));
  v.push_back(make_pair("red", "Reality"));
  v.push_back(make_pair("yellow", "Mind "));
  for (long long int i = 0; i < n; i++) cin >> s[i];
  cout << 6 - n << endl;
  long long int flag = 0;
  for (long long int i = 0; i < 6; i++) {
    flag = 0;
    for (long long int j = 0; j < n; j++) {
      if (s[j] == v[i].first) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) cout << v[i].second << endl;
  }
  return 0;
}
