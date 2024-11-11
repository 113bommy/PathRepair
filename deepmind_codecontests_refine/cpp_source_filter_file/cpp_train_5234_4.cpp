#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,avx,avx2")
#pragma GCC optimize("unroll-loops")
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
template <class T>
ostream& operator<<(ostream& str, vector<T>& a) {
  for (auto& i : a) {
    str << i << " ";
  }
  return str;
}
template <class T>
istream& operator>>(istream& str, vector<T>& a) {
  for (auto& i : a) {
    str >> i;
  }
  return str;
}
template <class T>
ostream& operator<<(ostream& str, pair<T, T>& a) {
  str << a.first << " " << a.second;
  return str;
}
template <class T>
istream& operator>>(istream& str, pair<T, T>& a) {
  str >> a.first >> a.second;
  return str;
}
void solve() {
  LL n, s;
  cin >> n >> s;
  LL sum = 0;
  LL tn = n;
  while (tn > 0) {
    sum += tn % 10;
    tn = tn / 10;
  }
  if (sum == s) {
    cout << 0 << endl;
  } else {
    string tstr = to_string(n);
    int i = 0;
    LL tsum = 0;
    for (i = 0; i < tstr.size(); i++) {
      tsum += (LL)(tstr[i] - '0');
      if (tsum >= s) break;
    }
    LL posDiff = (LL)(tstr.size() - i);
    LL base = pow(10, posDiff);
    LL move = (LL)pow(10, posDiff);
    LL diff = base - n % move;
    cout << diff << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
