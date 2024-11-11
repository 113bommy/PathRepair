#include <bits/stdc++.h>
using namespace std;
long long bp(long long a, long long b, long long mod = 1e9 + 7) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
const long long INF = 1e16;
const long long mod = 1e9 + 7;
int n;
char c;
int freq = -1;
void print(map<char, int> &last) {
  for (auto x : last) {
    for (int i = 0; i < (x.second) / 2; i++) {
      cout << x.first;
    }
  }
  for (int i = 0; i < min(1, freq); i++) cout << c;
  for (auto it = last.rbegin(); it != last.rend(); it++) {
    for (int i = 0; i < (it->second) / 2; i++) cout << it->first;
  }
}
void solve() {
  string s;
  cin >> s;
  n = (int)s.size();
  map<char, int> m;
  for (char c : s) m[c] += 1;
  map<char, int> odd, last;
  for (auto x : m) {
    if (x.second & 1) {
      odd[x.first] = x.second;
    } else {
      last[x.first] = x.second;
    }
  }
  int sz = (int)odd.size();
  auto start = odd.begin();
  auto end = odd.rbegin();
  for (int i = 0; i < sz / 2; i++) {
    last[start->first] = start->second + 1;
    last[end->first] = end->second - 1;
    odd[start->first] = 0, odd[end->first] = 0;
    start++, end++;
  }
  for (auto x : odd) {
    if (x.second != 0) {
      last[x.first] = x.second;
      c = x.first, freq = x.second;
      break;
    }
  }
  print(last);
}
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long ttt = 1;
  for (long long rep = 1; rep <= ttt; rep++) {
    solve();
  }
}
