#include <bits/stdc++.h>
using namespace std;
long long powr(int x, int y) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    long long temp = pow(x, y / 2);
    return (temp * temp);
  }
  return x * pow(x, y - 1);
}
long long n;
string s;
map<string, long long> res;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (long long i = 0; i < s.size(); i++) {
    if (i + 1 < s.size()) {
      string temp = "";
      temp += s[i];
      temp += s[i + 1];
      res[temp]++;
    }
  }
  long long mx = -1000000000000000;
  string s2;
  for (std::map<string, long long>::iterator it = res.begin(); it != res.end();
       it++) {
    if (it->second > mx) {
      s2 = it->first;
      mx = it->second;
    }
  }
  cout << s2;
  return 0;
}
