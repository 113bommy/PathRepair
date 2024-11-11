#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int mod[2] = {98765431, (int)1e9 + 9};
int base = 71;
int n;
int a[N];
int b[N], c[N];
int num[N];
map<pair<long long, long long>, int> mp;
int nbit(int x) {
  int ans = 0;
  while (x) ans += x & 1, x /= 2;
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[i] = (a[i] >> 16);
    b[i] = (a[i] - (c[i] << 16));
  }
  for (int i = 0; i < (1 << 16); i++) {
    for (int j = 0; j < n; j++) num[j] = nbit(b[j] ^ i);
    pair<long long, long long> h = {0, 0};
    for (int j = 0; j < n; j++) {
      h.first = (h.first * base + (num[j] - num[0])) % mod[0];
      h.second = (h.second * base + (num[j] - num[0])) % mod[1];
    }
    if (!mp[h]) mp[h] = i + 1;
  }
  for (int i = 0; i < (1 << 16); i++) {
    for (int j = 0; j < n; j++) num[j] = nbit(c[j] ^ i);
    pair<long long, long long> h = {0, 0};
    for (int j = 0; j < n; j++) {
      h.first = (h.first * base - (num[j] - num[0])) % mod[0];
      h.second = (h.second * base - (num[j] - num[0])) % mod[1];
    }
    if (mp[h]) {
      cout << (i << 16) + mp[h] - 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
