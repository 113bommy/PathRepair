#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const string ln = "\n";
const string alph = "abcdefghijklmnopqrstuvwxyz";
void printv(vector<int> &s) {
  for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
  }
  cout << ln;
}
int main() {
  int tq;
  cin >> tq;
  for (int ti = 0; ti < tq; ti++) {
    string s;
    cin >> s;
    if (s.length() == 1) {
      cout << "YES\n" << s;
      for (int i = 0; i < 26; i++) {
        if (alph[i] != s[0]) {
          cout << alph[i];
        }
      }
      cout << ln;
      continue;
    }
    map<char, vector<char> > p;
    map<char, map<char, bool> > n;
    for (int i = 0; i < 26; i++) {
      p[alph[i]] = vector<char>();
      for (int j = 0; j < 26; j++) {
        n[alph[i]][alph[j]] = 0;
      }
    }
    for (int i = 1; i < s.length(); i++) {
      char a = s[i], b = s[i - 1];
      if (!n[a][b]) {
        p[a].push_back(b);
        n[a][b] = 1;
      }
      if (!n[b][a]) {
        p[b].push_back(a);
        n[b][a] = 1;
      }
    }
    bool br = 0;
    char n1 = '.', n2 = '.';
    for (int i = 0; i < 26; i++) {
      char c = alph[i];
      if (p[c].size() == 0) {
        continue;
      }
      if (p[c].size() > 2) {
        br = 1;
        break;
      }
      if (p[c].size() == 1) {
        if (n1 != '.' && n2 != '.') {
          br = 1;
          break;
        }
        if (n1 == '.') {
          n1 = c;
        } else {
          n2 = c;
        }
      }
    }
    if (n1 == '.' || n2 == '.' || br) {
      cout << "NO\n";
      continue;
    }
    string ans = "";
    ans += n1;
    ans += p[n1][0];
    map<char, bool> u;
    for (int i = 0; i < 26; i++) {
      u[alph[i]] = 0;
    }
    u[ans[0]] = 1;
    u[ans[1]] = 1;
    while (ans[ans.length() - 1] != n2) {
      char c = ans[ans.length() - 1];
      char l = p[c][0], r = p[c][1];
      if (u[l] && u[r]) {
        br = 1;
        break;
      }
      if (u[l]) {
        ans += r;
        u[r] = 1;
      } else {
        u[l] = 1;
        ans += l;
      }
    }
    if (br) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < 26; i++) {
      char c = alph[i];
      if (!u[c]) {
        ans += c;
      }
    }
    if (ans.length() != 26) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << ans << ln;
    }
  }
}
