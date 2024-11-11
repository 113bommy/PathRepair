#include <bits/stdc++.h>
using namespace std;
const int MX = 3005;
string S;
vector<int> pi;
void CalcKmp() {
  pi.resize(S.size());
  for (int i = 1; i < (int)S.size(); i++) {
    int tt = pi[i - 1];
    while (tt && S[i] != S[tt]) {
      tt = pi[tt - 1];
    }
    pi[i] = tt + (S[i] == S[tt]);
  }
}
string s[MX];
string T;
void transform(int x) {
  int n = s[x].size();
  int pr = 0;
  for (int i = 0; i < n; i++) {
    int tt = pr;
    while (tt && s[x][i] != S[tt]) {
      tt = pi[tt - 1];
    }
    pr = tt + (s[x][i] == S[tt]);
    if (pr == (int)S.size()) {
      for (int t = 0; t < pr; t++) {
        int j = i - pr + 1 + t;
        s[x][j] = T[t];
      }
      return;
    }
  }
}
string t[MX];
bool changed[MX];
int L[MX], R[MX];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    int m = s[i].length();
    L[i] = m;
    for (int j = 0; j < m; j++) {
      if (s[i][j] != t[i][j]) {
        changed[i] = true;
        L[i] = min(L[i], j);
        R[i] = j;
      }
    }
  }
  int frst = 0;
  while (!changed[frst]) frst++;
  for (int i = frst + 1; i < n; i++) {
    if (!changed[i]) continue;
    if (R[i] - L[i] != R[frst] - L[frst]) {
      cout << "NO";
      return 0;
    }
    int sz = R[i] - L[i];
    int x = L[frst];
    int y = L[i];
    for (int j = 0; j <= sz; j++) {
      if (s[frst][x] != s[i][y]) {
        cout << "NO";
        return 0;
      }
      if (t[frst][x] != t[i][x]) {
        cout << "NO";
        return 0;
      }
      x++, y++;
    }
  }
  while (true) {
    if (L[frst] == 0) break;
    char c1 = s[frst][L[frst] - 1];
    char c2 = t[frst][L[frst] - 1];
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (!changed[i]) continue;
      if (L[i] == 0) {
        ok = false;
        break;
      }
      if (s[i][L[i] - 1] != c1 || t[i][L[i] - 1] != c2) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    for (int i = 0; i < n; i++) {
      if (changed[i]) {
        L[i]--;
      }
    }
  }
  while (true) {
    if (R[frst] == (int)s[frst].size() - 1) break;
    char c1 = s[frst][R[frst] + 1];
    char c2 = t[frst][R[frst] + 1];
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (!changed[i]) continue;
      if (R[i] == (int)s[i].size() - 1) {
        ok = false;
        break;
      }
      if (s[i][R[i] + 1] != c1 || t[i][R[i] + 1] != c2) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    for (int i = 0; i < n; i++) {
      if (changed[i]) {
        R[i]++;
      }
    }
  }
  for (int i = L[frst]; i <= R[frst]; i++) {
    S += s[frst][i];
    T += t[frst][i];
  }
  CalcKmp();
  for (int i = 0; i < n; i++) {
    transform(i);
    if (s[i] != t[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  cout << S << "\n";
  cout << T << endl;
}
