#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18;
string ans;
bool ask(string s) {
  cout << "? " << s << endl;
  int q;
  cin >> q;
  bool is = q > 0;
  while (q--) {
    int pos;
    cin >> pos;
    --pos;
    for (int i = 0; i < int((s).size()); i++) ans[pos + i] = s[i];
  }
  return is;
}
void solve4() {
  ask("CO");
  ask("CH");
  ask("OH");
  vector<int> ind;
  for (int i = 0; i < 4; i++)
    if (ans[i] == '?') ind.push_back(i);
  if (ind.empty()) return;
  if (int((ind).size()) == 1) {
    for (char c : {'O', 'H', 'C'}) {
      ans[ind[0]] = c;
      if (ask(ans)) return;
    }
  }
  if (int((ind).size()) == 2) {
    for (char c1 : {'O', 'H', 'C'})
      for (char c2 : {'O', 'H', 'C'}) {
        ans[ind[0]] = c1, ans[ind[1]] = c2;
        if (ask(ans)) return;
      }
  }
  ask("OC");
  if (ans[0] != '?' && ans[1] != '?') {
    ans[2] = ans[3] = 'C';
    return;
  }
  if (ans[1] != '?' && ans[2] != '?') {
    ans[3] = 'C';
    for (char c : {'O', 'H', 'C'}) {
      ans[0] = c;
      if (ask(ans)) return;
    }
  }
  if (ans[2] != '?' && ans[3] != '?') {
    for (char c1 : {'O', 'H'})
      for (char c2 : {'O', 'H'}) {
        ans[0] = c1, ans[0] = c2;
        if (ask(ans)) return;
      }
  }
  ask("HHH");
  ask("CCC");
  ask("OOO");
  if (ans[0] != '?' && ans[3] != '?') return;
  if (ans[0] == '?' && ans[1] != '?') {
    ans[0] = 'H';
    if (ask(ans)) return;
    ans[0] = 'O';
    return;
  }
  if (ans[3] == '?' && ans[2] != '?') {
    ans[3] = 'C';
    if (ask(ans)) return;
    ans[3] = 'O';
    return;
  }
  if (ask("HHOO")) return;
  ans = "HHCC";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    ans = "";
    for (int i = 0; i < n; i++) ans += '?';
    if (n == 4) {
      solve4();
    } else {
      ask("CH");
      ask("CO");
      ask("CC");
      int pt = -1;
      for (int i = 0; i < n; i++) {
        if (ans[i] != '?') pt = i;
      }
      if (pt == -1) {
        ask("OH");
        ask("HO");
        pt = -1;
        for (int i = 0; i < n; i++)
          if (ans[i] != '?') pt = i;
        if (pt == -1) {
          string s = "";
          for (int i = 0; i < n - 1; i++) s += "H";
          ask(s);
          if (ans[0] == '?')
            for (int i = 0; i < n - 1; i++) ans[i] = 'O';
          ans[n - 1] = ans[n - 2];
        } else {
          for (int i = pt - 1; i >= 0; i--)
            if (ans[i] == '?') ans[i] = ans[i + 1];
          for (int i = pt + 1; i < n; i++)
            if (ans[i] == '?') ans[i] = ans[i - 1];
        }
      } else {
        for (int i = pt - 1; i >= 0; i--) {
          if (ans[i] == '?') {
            string s = ans.substr(i + 1, pt - i);
            s = 'H' + s;
            ask(s);
            if (ans[i] == '?') ans[i] = 'O';
          }
        }
        for (int i = pt + 1; i < n; i++) {
          if (ans[i] == '?') {
            ask(ans.substr(0, i) + 'H');
            if (ans[i] == '?') ans[i] = 'O';
          }
        }
      }
      ask(ans.substr(0, n - 1) + 'C');
    }
    cout << "! " << ans << endl;
    bool ret;
    cin >> ret;
    if (ret == 0) return 0;
  }
  return 0;
}
