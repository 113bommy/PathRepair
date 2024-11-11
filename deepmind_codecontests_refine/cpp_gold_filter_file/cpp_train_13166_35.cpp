#include <bits/stdc++.h>
using namespace std;
int like[256];
int main() {
  for (int i = 'a'; i <= 'z'; ++i) cin >> like[i];
  string s;
  cin >> s;
  long long res = 0;
  for (int c = 'a'; c <= 'z'; ++c) {
    long long cur = 0;
    map<long long, long long> cnt;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == c) {
        res += cnt[cur];
        cur += like[s[i]];
        cnt[cur] += 1;
      } else {
        cur += like[s[i]];
      }
    }
  }
  cout << res << endl;
  return 0;
}
