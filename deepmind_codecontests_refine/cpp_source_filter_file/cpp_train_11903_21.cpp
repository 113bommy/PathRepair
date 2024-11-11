#include <bits/stdc++.h>
using namespace std;
long long bef[1000100], af[1000100];
long long calc(int n) { return (n * (n + 1)) / 2; }
int main() {
  int k;
  string s;
  cin >> k >> s;
  memset(bef, 0, sizeof bef);
  memset(af, 0, sizeof af);
  long long last(1000010), cur(1), i(0);
  vector<int> ones;
  long long incase(0);
  while (i < s.size()) {
    while (s[i] == '0') {
      ++i;
      ++cur;
    }
    incase += calc(cur - 1);
    if (i < s.size()) {
      bef[i] = cur;
      cur = 1;
      ones.push_back(i);
    }
    ++i;
  }
  if (!k) {
    cout << incase;
    return 0;
  }
  i = s.size() - 1;
  cur = 1;
  while (i >= 0) {
    while (s[i] == '0') {
      --i;
      ++cur;
    }
    if (i >= 0) {
      af[i] = cur;
      cur = 1;
    }
    --i;
  }
  long long ans(0);
  for (int j = 0; j + k - 1 < ones.size(); ++j) {
    ans += bef[ones[j]] * af[ones[j + k - 1]];
  }
  cout << ans;
  return 0;
}
