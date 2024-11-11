#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int ans[7] = {0};
string s = "1689";
void solve(int rem, int done[]) {
  if (rem > 1000) {
    for (int i = 0; i < 7; i++) {
      rem = i * 10000 + rem;
      if (rem % 7 == 0) ans[i] = rem - i * 10000;
      rem -= 10000 * i;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (done[i] == 0) {
      done[i] = 1;
      rem = rem * 10 + s[i] - 48;
      solve(rem, done);
      rem -= (s[i] - 48);
      rem /= 10;
      done[i] = 0;
    }
  }
}
void solution() {
  int i, j, k, m;
  int done[4] = {0};
  string str;
  cin >> str;
  int rem = 0;
  solve(rem, done);
  set<int> dig;
  dig.insert(1);
  dig.insert(6);
  dig.insert(8);
  dig.insert(9);
  string temp = "";
  int cnt = 0;
  for (char c : str) {
    if (c == '0') {
      cnt++;
      continue;
    }
    if (dig.count(c - 48)) {
      dig.erase(c - 48);
    } else
      temp += str[i];
  }
  rem = 0;
  int n = temp.size();
  for (int i = 0; i < n; i++) {
    rem = rem * 10 + temp[i] - 48;
    rem = rem % 7;
  }
  cout << temp;
  cout << ans[rem];
  for (int i = 0; i < cnt; i++) cout << 0;
}
int main() {
  int t = 1;
  while (t--) {
    solution();
  }
  return 0;
}
