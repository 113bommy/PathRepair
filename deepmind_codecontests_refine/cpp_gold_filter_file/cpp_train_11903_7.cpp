#include <bits/stdc++.h>
using namespace std;
vector<int> me;
long long sum(long long x) { return (x * (x + 1)) / 2; }
int main() {
  int k;
  string s;
  cin >> k >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      me.push_back(i);
    }
  }
  long long ans = 0, cnt = 0, idx = -1;
  if (k == 0) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        ans += sum(cnt);
        cnt = 0;
      } else {
        cnt++;
      }
    }
    ans += sum(cnt);
  } else {
    long long fst = -1;
    for (int i = 0; i < me.size(); i++) {
      int idx = me[i];
      cnt = 0;
      if ((i + k - 1) == me.size() - 1) {
        ans += ((idx - fst) * (s.size() - me[i + k - 1]));
      } else if (i + k - 1 < me.size() - 1) {
        ans += ((idx - fst) * (me[i + k] - me[i + k - 1]));
      }
      fst = me[i];
    }
  }
  cout << ans;
  return 0;
}
