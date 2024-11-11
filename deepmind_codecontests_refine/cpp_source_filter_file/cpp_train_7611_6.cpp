#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const int maxn = 1e6 + 5;
int k;
int n;
string s, a, b;
map<char, char> mp;
map<char, int> mpc;
set<char> used;
bool apply(char c, char d) {
  if (mp.count(c)) {
    if (mp[c] == d) {
      mpc[c]++;
      return true;
    } else {
      return false;
    }
  }
  if (used.count(d)) {
    return false;
  }
  mp[c] = d;
  used.insert(d);
  mpc[c]++;
  return true;
}
void undo(char c, char d) {
  if (--mpc[c] == 0) {
    mp.erase(c);
    used.erase(d);
  }
}
bool dfs(int i, bool ea = true, bool eb = true) {
  if (i == n) {
    return true;
  }
  if (ea && eb) {
    for (char c = a[i]; c <= b[i]; c++) {
      if (apply(s[i], c)) {
        if (dfs(i + 1, ea && c == a[i], eb && c == b[i])) {
          return true;
        }
        undo(s[i], c);
      }
    }
    return false;
  } else if (!ea && eb) {
    for (char c = 'a'; c <= b[i]; c++) {
      if (apply(s[i], c)) {
        if (dfs(i + 1, ea && c == a[i], eb && c == b[i])) {
          return true;
        }
        undo(s[i], c);
      }
    }
    return false;
  } else if (ea && !eb) {
    for (char c = char('a' + k - 1); c >= 'a'; c--) {
      if (apply(s[i], c)) {
        if (dfs(i + 1, ea && c == a[i], eb && c == b[i])) {
          return true;
        }
        undo(s[i], c);
      }
    }
    return false;
  } else {
    return true;
  }
}
void solve() {
  cin >> k;
  cin >> s >> a >> b;
  n = s.length();
  mp.clear();
  mpc.clear();
  used.clear();
  if (dfs(0)) {
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
      char c = char('a' + i);
      if (!mp.count(c)) {
        char d = 'a';
        while (used.count(d)) d++;
        mp[c] = d;
        used.insert(d);
      }
      cout << mp[c];
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
