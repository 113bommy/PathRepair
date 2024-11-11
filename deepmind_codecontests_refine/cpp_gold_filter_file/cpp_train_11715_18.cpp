#include <bits/stdc++.h>
using namespace std;
long long ans[2000006];
long long lans[30];
long long mod = 1e9 + 7;
priority_queue<pair<int, int> > pq;
int a[26];
string s;
int n, k;
long long mx;
void calc() {
  memset(lans, 0, sizeof(lans));
  memset(ans, 0, sizeof(ans));
  n = s.size();
  for (int i = 0; i < n; i++) {
    ans[i + 1] = 2 * ans[i] + 1 - lans[s[i] - 'a'] + mod;
    ans[i + 1] %= mod;
    lans[s[i] - 'a'] = ans[i] + 1;
    lans[s[i] - 'a'] %= mod;
  }
  cout << (1 + ans[n]) % mod << endl;
}
int main() {
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < s.size(); i++) a[s[i] - 'a'] = i + 1;
  for (int i = 0; i < k; i++) pq.push(make_pair(-a[i], i));
  for (int j = 0; j < n; j++) {
    auto u = pq.top();
    pq.pop();
    s += ('a' + u.second);
    u.first = -s.size();
    pq.push(u);
  }
  calc();
  return 0;
}
