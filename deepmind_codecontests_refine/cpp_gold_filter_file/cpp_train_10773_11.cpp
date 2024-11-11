#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long cnt(int p1, int p2) {
  if (p1 == p2)
    return s[p1] - '0';
  else {
    long long curr = s[p1] - '0';
    for (int i = p1 + 1; i <= p2; i += 2) {
      if (s[i] == '*')
        curr *= (s[i + 1] - '0');
      else
        return curr + cnt(i + 1, p2);
    }
    return curr;
  }
}
long long go(int p1, int p2) {
  long long lf = 0;
  long long ans = cnt(p1, p2);
  long long rg = 0;
  for (int i = p1 - 1; i >= 0; i -= 2) {
    if (s[i] == '*')
      ans *= (s[i - 1] - '0');
    else {
      lf = cnt(0, i - 1);
      break;
    }
  }
  for (int i = p2 + 1; i < n; i += 2) {
    if (s[i] == '*')
      ans *= (s[i + 1] - '0');
    else {
      rg = cnt(i + 1, n - 1);
      break;
    }
  }
  return rg + lf + ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  s = "1*" + s + "*1";
  n = s.length();
  vector<int> pos;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') pos.push_back(i);
  }
  for (int i = 0; i < pos.size(); i++) {
    for (int j = i + 1; j < pos.size(); j++) {
      int pos1 = pos[i] + 1;
      int pos2 = pos[j] - 1;
      ans = max(ans, go(pos1, pos2));
    }
  }
  cout << ans;
  return 0;
}
