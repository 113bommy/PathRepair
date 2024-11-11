#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int dp[N];
string s;
vector<string> o;
bool repeat(int a, int b, int c) {
  if (b + c >= s.size()) return false;
  for (int i = a; i <= b; ++i)
    if (s[a] != s[a + c]) return false;
  return true;
}
string gen(int a, int b) {
  string temp = "";
  for (int i = a; i <= b; ++i) temp.push_back(s[i]);
  return temp;
}
int main() {
  cin >> s;
  if (s.size() <= 6) {
    cout << "0" << endl;
    return 0;
  }
  dp[s.size()] = 1;
  o.push_back(gen(s.size() - 2, s.size() - 1));
  dp[s.size() - 2] = 1;
  if (s.size() >= 8) {
    o.push_back(gen(s.size() - 3, s.size() - 1));
    dp[s.size() - 3] = 1;
  }
  for (int i = s.size() - 4; i >= 5; --i) {
    if (dp[i + 2] == 1) {
      if (!repeat(i, i + 1, 2)) {
        o.push_back(gen(i, i + 1));
        dp[i] = 1;
      } else if (dp[i + 2 + 3] == 1) {
        o.push_back(gen(i, i + 1));
        dp[i] = 1;
      }
    }
    if (dp[i + 3] == 1) {
      if (!repeat(i, i + 2, 3)) {
        o.push_back(gen(i, i + 2));
        dp[i] = 1;
      } else if (dp[i + 3 + 2] == 1) {
        o.push_back(gen(i, i + 2));
        dp[i] = 1;
      }
    }
  }
  sort(o.begin(), o.end());
  o.resize(unique(o.begin(), o.end()) - o.begin());
  cout << o.size() << endl;
  for (int i = 0; i < o.size(); ++i) cout << o[i] << endl;
}
