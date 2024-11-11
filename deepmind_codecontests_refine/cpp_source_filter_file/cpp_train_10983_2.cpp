#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt[2] = {0};
  for (char c : s)
    if (('A' <= c) && ('Z' >= c))
      cnt[0]++;
    else
      cnt[1]++;
  cnt[0] < cnt[1] ? transform(s.begin(), s.end(), s.begin(), ::tolower)
                  : transform(s.begin(), s.end(), s.begin(), ::toupper);
  cout << s;
}
