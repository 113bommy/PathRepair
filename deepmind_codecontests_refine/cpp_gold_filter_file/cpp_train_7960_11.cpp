#include <bits/stdc++.h>
using namespace std;
long long stoi(string s) {
  long long l = s.length();
  long long n = 0;
  for (long long i = 0; i < l; i++) {
    n = n * 10 + s[i] - '0';
  }
  return n;
}
int main() {
  long long i, j, num[100005], n, y;
  char str[100005];
  string ans, x;
  map<long long, string> m;
  m[0] = "";
  m[1] = "";
  m[2] = "2";
  m[3] = "3";
  m[4] = "322";
  m[5] = "5";
  m[6] = "53";
  m[7] = "7";
  m[8] = "7222";
  m[9] = "7332";
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> str[i];
    num[i] = str[i] - '0';
  }
  ans = "";
  x = "";
  y = 0;
  string::size_type sz = 0;
  for (i = 0; i < n; i++) {
    y = 0;
    x = "";
    ans += m[num[i]];
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans;
  return 0;
}
