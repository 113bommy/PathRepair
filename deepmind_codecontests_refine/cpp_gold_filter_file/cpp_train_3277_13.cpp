#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
bool compare_int(int a, int b) { return (a > b); }
bool compare_string(string a, string b) { return a.size() < b.size(); }
bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second)
    return a.first > b.first;
  else
    return (a.second > b.second);
}
long long int fact(long long int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
int cnt[200005];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, s1;
  s1 = ".";
  int n, q, x;
  cin >> s >> n;
  s1 += s;
  int l = s1.size();
  for (int i = 0; i < n; i++) {
    cin >> x;
    cnt[x]++;
    cnt[l - x + 1]++;
  }
  for (int i = 1; i < l; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i < l; i++) {
    if (cnt[i] % 2)
      cout << s1[l - i];
    else
      cout << s1[i];
  }
}
