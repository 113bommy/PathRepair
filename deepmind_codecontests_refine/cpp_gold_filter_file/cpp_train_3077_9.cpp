#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  getline(cin, s);
  vector<string> MSG;
  int last = 0;
  bool sign = false;
  for (int k = 0; k < s.size();) {
    string text = "";
    int j = 0;
    for (j = k; j < s.size(); ++j) {
      char c = s[j];
      if (c == '?' || c == '!' || c == '.') {
        sign = true;
        break;
      } else
        text += c;
    }
    last = k;
    k += j + 2 - last;
    MSG.push_back(text);
  }
  vector<int> sizes;
  for (int j = 0; j < MSG.size(); ++j) sizes.push_back(MSG[j].size() + 1);
  for (int j = 0; j < sizes.size(); ++j) {
    if (sizes[j] > n) {
      cout << "Impossible";
      return 0;
    }
  }
  int res = 0;
  int i = 0;
  while (i < sizes.size()) {
    int l = sizes[i];
    ++i;
    ++res;
    while (l + sizes[i] + 1 <= n && i < sizes.size()) {
      l += sizes[i] + 1;
      ++i;
    }
  }
  cout << res;
  return 0;
}
