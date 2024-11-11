#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433832795;
using namespace std;
long long mod = 1e9 + 7;
bool isp(char c) { return c == '?' || c == '!' || c == '.'; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(12);
  cout << fixed;
  string s, curr = "";
  vector<string> sent;
  int len;
  cin >> len;
  while (cin >> s) {
    curr += s + " ";
    if (isp(s[s.size() - 1])) sent.push_back(curr), curr = "";
  }
  int mn = 0;
  for (int i = 0; i < sent.size();) {
    int tot = sent[i].size() - 1, j;
    if (tot > len) {
      cout << "Impossible" << '\n';
      return 0;
    }
    for (j = i + 1; j < sent.size() && tot + sent[j].size() <= len; ++j)
      tot += sent[j].size();
    ++mn, i = j;
  }
  cout << mn << '\n';
  return 0;
}
