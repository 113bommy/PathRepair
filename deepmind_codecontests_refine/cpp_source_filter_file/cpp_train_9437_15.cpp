#include <bits/stdc++.h>
using namespace std;
void no() {
  cout << "No";
  exit(0);
}
void yes() {
  cout << "Yes";
  exit(0);
}
signed main() {
  string s;
  cin >> s;
  vector<long long> cnt(26, 0);
  long long res = 0;
  long long mn = 10000000;
  for (long long i = 0; i < s.size(); ++i) {
    cnt[s[i] - 'a']++;
    if (cnt[s[i] - 'a'] == 1) res++;
  }
  for (long long i = 0; i < 26; ++i) {
    if (i != 0) mn = min(mn, cnt[i]);
  }
  if (res > 4) no();
  if (res == 4) {
    yes();
  }
  if (res == 1) {
    no();
  }
  if (res == 2) {
    if (mn == 1) {
      no();
    } else {
      yes();
    }
  }
  if (res == 3) {
    if (s.size() == 3) no();
    yes();
  }
}
