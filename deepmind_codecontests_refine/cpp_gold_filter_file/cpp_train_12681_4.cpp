// https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
using namespace std;

string longer(string const& a, string const& b) {
  if (a.length() < b.length())
    return b;
  return a;
}

int main() {
  string s, t;
  cin >> s >> t;
  string lcs[2][t.length() + 1];

  for (int i = 1; i <= s.length() + 1; ++i)
    for (int j = 1; j <= t.length(); ++j) {
      lcs[i % 2][j] = longer(lcs[i % 2][j - 1], lcs[(i + 1) % 2][j]); 
      if (s[i - 1] == t[j - 1])
        lcs[i % 2][j] = lcs[(i + 1) % 2][j - 1] + s[i - 1];
    }
      
  cout << lcs[1][t.length()] << endl;
}
