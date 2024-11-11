#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<char> l;
vector<char> r;
void solve() {
  l[0] = s[0];
  for (int i = 1; i < s.size(); i++) {
    l[i] = max(l[i - 1], s[i]);
  }
  r.back() = s.back();
  for (int i = s.size() - 2; i >= 0; i--) {
    r[i] = min(r[i + 1], s[i]);
  }
  int a, b;
  bool ok = false;
  for (int i = 0; i < s.size() - 1; i++) {
    char u = l[i];
    char v = r[i + 1];
    if (u > v) {
      a = l[i];
      b = r[i + 1];
      ok = true;
      break;
    }
  }
  if (!ok) {
    cout << "NO";
    return;
  };
  int posa, posb;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == a) {
      posa = i;
      break;
    }
  for (int i = s.size() - 1; i >= 0; i--)
    if (s[i] == b) {
      posb = i;
      break;
    }
  cout << "YES\n" << ++posa << ' ' << ++posb;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  l.assign(n, 'a');
  r.assign(n, 'a');
  solve();
}
