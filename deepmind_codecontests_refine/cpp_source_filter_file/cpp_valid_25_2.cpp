#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Is_tp(string t, int k);
string Trans_t(string t, int tp);
string rv(string s);
int main() {
  ll t;
  cin >> t;
  for (ll i = 0; i < t; i++) {
    string s, t;
    cin >> s >> t;
    bool find = 0;
    for (int j = 0; j < t.size(); j++) {
      if (Is_tp(t, j)) {
        int f = s.find(Trans_t(t, j));
        if (f != -1) {
          cout << "YES" << endl;
          find = 1;
          break;
        }
      }
    }
    if (!find) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
bool Is_tp(string t, int k) {
  if (k == 0 || k == t.size() - 1) {
    return 1;
  }
  if (k <= t.size() / 2) {
    if (t.substr(0, k) == rv(t.substr(k + 1, k))) {
      return 1;
    } else {
      return 0;
    }
  } else {
    if (t.substr(k + 1, t.size() - k - 1) ==
        rv(t.substr(2 * k + 1 - t.size(), t.size() - k - 1))) {
      return 1;
    } else {
      return 0;
    }
  }
  return 0;
}
string Trans_t(string t, int tp) {
  string ans;
  if (tp < t.size() / 2) {
    ans = rv(t.substr(tp, t.size() - tp));
  } else {
    ans = t.substr(0, tp + 1);
  }
  return ans;
}
string rv(string s) {
  string t = s;
  for (int i = 0; i < s.size(); i++) {
    t[i] = s[s.size() - i - 1];
  }
  return t;
}
