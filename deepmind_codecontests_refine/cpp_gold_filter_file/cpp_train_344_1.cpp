#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  t.push_back('a' - 1);
  vector<int> have(256);
  for (int i = 0; i < s.length(); ++i) ++have[s[i]];
  int pref_len = 0;
  for (int i = 0; i < t.length() - 1; ++i) {
    if (!have[t[i]]) break;
    --have[t[i]];
    for (int j = t[i + 1] + 1; j <= 'z'; ++j) {
      if (have[j]) {
        pref_len = i + 1;
        break;
      }
    }
  }
  fill(have.begin(), have.end(), 0);
  for (int i = 0; i < s.length(); ++i) ++have[s[i]];
  if (!pref_len) {
    bool ok = false;
    for (int j = t[0] + 1; j <= 'z'; ++j) {
      if (have[j]) {
        cout << char(j);
        --have[j];
        for (int i = 'a'; i <= 'z'; ++i) {
          while (have[i]) {
            cout << char(i);
            --have[i];
          }
        }
        ok = true;
        break;
      }
    }
    if (!ok) cout << -1;
  } else {
    for (int i = 0; i < pref_len; ++i) {
      cout << t[i];
      --have[t[i]];
    }
    for (int i = t[pref_len] + 1; i <= 'z'; ++i) {
      if (have[i]) {
        cout << char(i);
        --have[i];
        break;
      }
    }
    for (int i = 'a'; i <= 'z'; ++i) {
      while (have[i]) {
        cout << char(i);
        --have[i];
      }
    }
  }
  return 0;
}
