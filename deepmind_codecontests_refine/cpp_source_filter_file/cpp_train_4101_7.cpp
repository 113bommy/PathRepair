#include <bits/stdc++.h>
using namespace std;
string tostr(int x) {
  string r = "";
  if (x == 0) return "0";
  while (x) {
    r += (x % 10 + '0');
    x /= 10;
  }
  reverse(r.begin(), r.end());
  return r;
}
string solve(long long x) {
  string res = "";
  for (int base = 24; base >= 0; base -= 8) {
    int r = 0;
    for (int i = 0; i < 8; i++) {
      r |= (((x >> (base + i)) & 1) << (i));
    }
    res += tostr(r) + " ."[base != 0];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    stringstream ss(s);
    string x;
    long long msk = 0;
    int cnt = 24;
    while (getline(ss, x, '.')) {
      long long y = atoi(x.c_str());
      msk |= (y << cnt);
      cnt -= 8;
    }
    v.push_back(msk);
  }
  long long sub = 0;
  for (int i = 31; i >= 0; i--) {
    sub |= (1ll << i);
    map<long long, int> mpp;
    for (int j = 0; j < n; j++) {
      mpp[v[j] & sub]++;
    }
    if ((int)mpp.size() == k) {
      cout << solve(sub) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
