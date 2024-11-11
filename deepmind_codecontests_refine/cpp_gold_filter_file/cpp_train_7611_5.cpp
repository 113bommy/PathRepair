#include <bits/stdc++.h>
using namespace std;
void Yes(int k, map<char, char> mp) {
  cout << "YES\n";
  set<char> used;
  for (auto &e : mp) used.insert(e.second);
  char nex = 'a';
  for (int i = 0; i < k; i++) {
    char c = 'a' + i;
    if (mp.count(c)) {
      cout << mp[c];
    } else {
      while (used.count(nex)) nex++;
      cout << nex++;
    }
  }
  cout << "\n";
}
void No() { cout << "NO\n"; }
void solve(int k, string s, string a, string b) {
  int n = s.size();
  map<char, char> mp;
  set<char> used;
  auto checkA = [&]() {
    for (int i = 0; i < n; i++) {
      if (mp.count(s[i])) {
        if (a[i] < mp[s[i]])
          return true;
        else if (a[i] == mp[s[i]])
          continue;
        else
          return false;
      }
      for (char c = a[i] + 1; c < 'a' + k; c++) {
        if (!used.count(c)) {
          mp[s[i]] = c;
          used.insert(c);
          return true;
        }
      }
      if (used.count(a[i])) return false;
      mp[s[i]] = a[i];
      used.insert(a[i]);
    }
    return true;
  };
  auto checkB = [&]() {
    for (int i = 0; i < n; i++) {
      if (mp.count(s[i])) {
        if (b[i] > mp[s[i]])
          return true;
        else if (b[i] == mp[s[i]])
          continue;
        else
          return false;
      }
      for (char c = 'a'; c < b[i]; c++) {
        if (!used.count(c)) {
          mp[s[i]] = c;
          used.insert(c);
          return true;
        }
      }
      if (used.count(b[i])) return false;
      mp[s[i]] = b[i];
      used.insert(b[i]);
    }
    return true;
  };
  for (int i = 0; i < n; i++) {
    if (mp.count(s[i])) {
      char c = mp[s[i]];
      if (c < a[i] || b[i] < c) {
        No();
        return;
      }
      if (a[i] < c && c < b[i]) {
        Yes(k, mp);
        return;
      }
      if (a[i] == c && b[i] == c) continue;
      if (a[i] == c) {
        if (checkA())
          Yes(k, mp);
        else
          No();
        return;
      }
      if (b[i] == c) {
        if (checkB())
          Yes(k, mp);
        else
          No();
        return;
      }
      assert(false);
    }
    if (a[i] == b[i]) {
      if (!used.count(a[i])) {
        mp[s[i]] = a[i];
        used.insert(a[i]);
        continue;
      } else {
        No();
        return;
      }
    }
    for (char c = a[i] + 1; c < b[i]; c++) {
      if (!used.count(c)) {
        mp[s[i]] = c;
        used.insert(c);
        Yes(k, mp);
        return;
      }
    }
    if (!used.count(a[i])) {
      auto tmpmp = mp;
      auto tmpused = used;
      mp[s[i]] = a[i];
      used.insert(a[i]);
      if (checkA()) {
        Yes(k, mp);
        return;
      }
      mp = tmpmp;
      used = tmpused;
    }
    if (!used.count(b[i])) {
      auto tmpmp = mp;
      auto tmpused = used;
      mp[s[i]] = b[i];
      used.insert(b[i]);
      if (checkB()) {
        Yes(k, mp);
        return;
      }
      mp = tmpmp;
      used = tmpused;
    }
    No();
    return;
  }
  Yes(k, mp);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k;
    string s, a, b;
    cin >> k >> s >> a >> b;
    solve(k, s, a, b);
  }
  return 0;
}
