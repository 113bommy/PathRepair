#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string remex(string s) {
  string t = "";
  for (int i = 0; s[i]; i++)
    if (s[i] == '*' || s[i] == '?')
      continue;
    else
      t += s[i];
  return t;
}
void solve() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '?')
      cnt1++;
    else if (s[i] == '*')
      cnt2++;
  }
  int slwe = s.length() - (cnt1 + cnt2);
  if (k == slwe) {
    cout << remex(s) << "\n";
  } else if (k > slwe) {
    if (cnt2) {
      string t = "";
      for (int i = 0; s[i]; i++) {
        if (s[i] == '*') {
          while (slwe < k) {
            t += s[i - 1];
            slwe++;
          }
          for (int j = i; s[j]; j++)
            if (s[j] != '*' && s[j] != '?') t += s[j];
          break;
        } else if (s[i] == '?') {
        } else {
          t += s[i];
        }
      }
      cout << t << "\n";
    } else {
      cout << "Impossible\n";
    }
  } else if (k >= slwe - (cnt1 + cnt2)) {
    string t = "";
    int rem = 0;
    for (int i = 0; s[i]; i++) {
      if (s[i] == '?' || s[i] == '*') continue;
      if (s[i + 1] == '?' || s[i + 1] == '*') {
        rem++;
        if (slwe - rem == k) {
          for (int j = i + 1; s[j]; j++)
            if (s[j] != '*' && s[j] != '?') t += s[j];
          break;
        }
        continue;
      }
      t += s[i];
    }
    cout << t << "\n";
  } else if (k < slwe - (cnt1 + cnt2)) {
    cout << "Impossible\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
