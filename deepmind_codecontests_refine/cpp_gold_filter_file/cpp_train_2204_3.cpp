#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mx = 1e5 + 5;
void Loser() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long fact(long long N) { return (N <= 1ll ? 1ll : N * fact(N - 1ll)); }
long long ceil(long long A, long long B) {
  if (A % B == 0)
    return A / B;
  else
    return (A / B) + 1ll;
}
long long middle(long long a, long long b, long long c) {
  if ((a <= b && b <= c) || (c <= b && b <= a))
    return b;
  else if ((b <= a && a <= c) || (c <= a && a <= b))
    return a;
  else
    return c;
}
bool ispalindrom(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return (s[0] == s[s.size() - 1] ? 1 : 0);
}
bool as_second(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool ds_first(const pair<long long, long long> &a,
              const pair<long long, long long> &b) {
  return (a.first > b.first);
}
bool ds_second(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return a.second > b.second;
}
template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> get_max(const std::map<KeyType, ValueType> &x) {
  using pairtype = std::pair<KeyType, ValueType>;
  return *std::max_element(x.begin(), x.end(),
                           [](const pairtype &p1, const pairtype &p2) {
                             return p1.second < p2.second;
                           });
}
string str, str1, str2, str3, str4, str5, str6, str7;
char ch, ch1, ch2, ch3;
bool flag, flag1, flag2;
long long a, b, c, d, e, f, g, h, l, i, j, k, m, n, o, p, q, r, s, t, u, v, w,
    x, y, z, test, cnt, cnt1, cnt2, cnt3, cnt4, sum, sum1, sum2, sum3, ans,
    ans1, ans2, ans3, ma, ma1, ma2, ma3, mi, mi1, mi2, mi3, temp, temp1, temp2,
    temp3, temp4;
void SectumSempra() {
  cin >> n >> m;
  vector<vector<char> > v(n, vector<char>(m));
  map<long long, long long> mp, mp1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == '*') mp[i]++, mp1[j]++;
    }
  }
  mi = 9e18;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      mi = min(mi, n + m - mp[i] - mp1[j] - (v[i][j] == '.'));
    }
  }
  cout << mi << endl;
  cout << endl;
}
int main() {
  Loser();
  cin >> test;
  while (test--) {
    SectumSempra();
  }
  return 0;
}
