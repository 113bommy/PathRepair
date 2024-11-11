#include <bits/stdc++.h>
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = bigmod(a, b / 2);
  return ret * ret % 1000000007 * (b % 2 ? a : 1) % 1000000007;
}
using namespace std;
long long n, p[500010];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  vector<int> v;
  long long cnt = 0, ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt++;
      while (!v.empty() && p[v.back()] < cnt) v.pop_back();
      if (v.empty())
        sum += i + 1;
      else
        sum += i - (v.back() - cnt + 1);
      v.push_back(i);
    } else
      cnt = 0;
    p[i] = cnt;
    ans += sum;
  }
  cout << ans;
}
