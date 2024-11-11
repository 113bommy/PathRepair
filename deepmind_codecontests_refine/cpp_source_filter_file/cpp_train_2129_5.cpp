#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (T i : v) os << i << ", ";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &v) {
  for (T i : v) os << i << " ";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  for (T i : v) os << i << " ";
  return os;
}
template <class T, class second>
ostream &operator<<(ostream &os, const pair<T, second> &v) {
  os << v.first << ' ' << v.second;
  return os;
}
template <class T, class second>
ostream &operator<<(ostream &os, const map<T, second> &v) {
  for (auto i : v) os << '(' << i.first << " => " << i.second << ')' << ' ';
  return os;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n;
vector<string> v;
vector<string> inv(25);
map<string, int> m;
void solve() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      string s = "";
      s.push_back(char(i + 'A'));
      s.push_back(char(j + '1'));
      m[s] = i * 5 + j;
      inv[i * 5 + j] = s;
    }
  }
  int have = 0;
  for (int i = 0; i < n; i++) {
    int bit = m[v[i]];
    have |= (1 << bit);
  }
  if (__builtin_popcount(have) == 1) {
    cout << 0 << "\n";
    return;
  }
  int ans = 1e9;
  for (int mask = 0; mask < (1 << 10); mask++) {
    set<int> temp;
    bool ok = 1;
    for (int i = 0; i < 25; i++) {
      if (!(have & (1 << i))) continue;
      int hint = 0;
      int alphabet_bit = i / 5;
      int number_bit = i % 5;
      if (mask & (1 << alphabet_bit)) hint |= (1 << alphabet_bit);
      if (mask & (1 << number_bit)) hint |= (1 << number_bit);
      if (temp.count(hint)) {
        ok = 0;
        break;
      }
      temp.insert(hint);
    }
    if (ok) ans = min(ans, int(__builtin_popcount(mask)));
  }
  cout << ans << "\n";
}
int main() {
  fast();
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'R')
      s[0] = 'A';
    else if (s[0] == 'G')
      s[0] = 'B';
    else if (s[0] == 'B')
      s[0] = 'C';
    else if (s[0] == 'Y')
      s[0] = 'D';
    else if (s[0] == 'W')
      s[0] = 'E';
    v.push_back(s);
  }
  solve();
}
