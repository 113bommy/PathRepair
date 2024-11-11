#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, N = 1e6 + 1;
int main() {
  long long count = 0, count2 = 0;
  string s;
  cin >> s;
  map<char, long long> mp;
  if (s.length() <= 3) {
    cout << "No";
    return 0;
  }
  for (long long i = 0; i < s.length(); i++) {
    mp[s[i]]++;
  }
  for (char c = 'a'; c != 'z' + 1; c++) {
    if (mp[c] > 0) count++;
    if (mp[c] >= 2) count2++;
  }
  if (count == 1 || count >= 4) {
    cout << "No";
    return 0;
  }
  if (count == 2)
    if (count2 <= 1) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}
