#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, x;
  string s;
  cin >> s;
  n = s.size();
  map<char, long long> mp;
  for (i = 0; i < n; i++) {
    long long temp = 0;
    for (char c = 'a'; c < s[i]; c++) temp += mp[c];
    if (temp == 0)
      cout << "Mike\n";
    else
      cout << "Ann\n";
    mp[s[i]]++;
  }
}
