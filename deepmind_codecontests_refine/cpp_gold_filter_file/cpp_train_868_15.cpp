#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<long long> q;
  string s;
  int n, m;
  cin >> n >> m;
  int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int MM, DD, hh, mm, ss;
  while (getline(cin, s)) {
    MM = (s[5] - '0') * 10 + s[6] - '0';
    DD = (s[8] - '0') * 10 + s[9] - '0';
    hh = (s[11] - '0') * 10 + s[12] - '0';
    mm = (s[14] - '0') * 10 + s[15] - '0';
    ss = (s[17] - '0') * 10 + s[18] - '0';
    for (int i = 1; i < MM; i++) {
      DD += month[i];
    }
    long long second = DD * 3600 * 24 + hh * 3600 + mm * 60 + ss;
    q.push(second);
    while (q.front() + n <= second) q.pop();
    if (q.size() >= m) {
      cout << s.substr(0, 19);
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
