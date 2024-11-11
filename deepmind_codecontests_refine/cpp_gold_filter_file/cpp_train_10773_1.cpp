#include <bits/stdc++.h>
using namespace std;
void put(int x, int t, stack<long long> &s) {
  if (t == 0)
    s.push(x);
  else {
    long long y = s.top();
    s.pop();
    s.push(y * x);
  }
}
long long res(stack<long long> &s) {
  long long ans = 0;
  while (!s.empty()) {
    ans += s.top();
    s.pop();
  }
  return ans;
}
long long compute(int n, int st, int e, string &str) {
  stack<long long> s[2];
  int lt = 0, is = 0;
  for (int i = 1; i < n; i += 2) {
    int x = str[i] - '0';
    int t = (str[i - 1] == '+' ? 0 : 1);
    if (i == st) {
      is = 1;
      lt = t;
      t = 0;
    }
    put(x, t, s[is]);
    if (i == e) {
      long long y = res(s[1]);
      put(y, lt, s[0]);
      is = 0;
    }
  }
  long long ans = res(s[is]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  s = "+" + s;
  int n = s.length();
  long long ans = compute(n, 1, n - 1, s);
  for (int i = 1; i < n; i += 2)
    for (int j = i; j < n; j += 2) {
      if (i >= 3 && s[i - 1] == '+' && s[i - 3] == '+') continue;
      if (j + 3 < n && s[j + 1] == '+' && s[j + 3] == '+') continue;
      ans = max(ans, compute(n, i, j, s));
    }
  cout << ans << endl;
  return 0;
}
