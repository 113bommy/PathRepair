#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const double pi = 3.14159265358979323846;
string uppercase(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
string lowercase(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string fact[10] = {"", "", "2", "3", "223", "5", "35", "7", "7222", "733222"};
  string res = "";
  for (int i = 0; i < n; ++i) {
    res += fact[s[i] - '0'];
  }
  sort(res.rbegin(), res.rend());
  cout << res;
  return 0;
}
