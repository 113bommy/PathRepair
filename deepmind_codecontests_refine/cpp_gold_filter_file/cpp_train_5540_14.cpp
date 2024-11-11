#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
const int b = 256;
string s;
long long int ph[maxn];
long long int pw[maxn];
inline long long int get(int l, int r);
inline bool check(int f);
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  pw[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    ph[i + 1] = (ph[i] * b + s[i]) % mod;
    pw[i + 1] = (b * pw[i]) % mod;
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (get(1, i + 1) == get(s.size() - i, s.size())) {
      v.push_back(i + 1);
    }
  }
  sort(v.begin(), v.end());
  if (v.size() == 0) {
    cout << "Just a legend";
    return 0;
  } else if (check(v[v.size() - 1]) == true) {
    for (int i = 0; i < v[v.size() - 1]; i++) {
      cout << s[i];
    }
  } else {
    if (v.size() == 1) {
      cout << "Just a legend";
      return 0;
    } else {
      for (int i = 0; i < v[v.size() - 2]; i++) {
        cout << s[i];
      }
    }
  }
  return 0;
}
inline long long int get(int l, int r) {
  return ((ph[r] - ((ph[l - 1] * pw[r - l + 1]) % mod)) + mod) % mod;
}
inline bool check(int f) {
  for (int i = 2; i <= s.size() - f; i++) {
    if (get(i, i + f - 1) == get(1, f)) {
      return true;
    }
  }
  return false;
}
