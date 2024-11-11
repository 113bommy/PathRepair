#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int acc[MAXN], sav[MAXN];
int extr(string &s) {
  int num = 0;
  for (int i = 1; i < s.length(); i++) {
    num *= 10;
    num += (s[i] - '0');
  }
  return num;
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int pl = 0, mn = 0;
  vector<string> statements;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    statements.push_back(s);
    int z = extr(s);
    if (s[0] == '+')
      acc[z]++, pl++;
    else
      sav[z]++, mn++;
  }
  set<int> Suspects;
  for (int i = 1; i < n + 1; i++) {
    int tr = acc[i] + mn - sav[i];
    if (tr == m) {
      Suspects.insert(i);
    }
  }
  for (int i = 0; i < n; i++) {
    string s = statements[i];
    int z = extr(s);
    if (s[0] == '+') {
      if (Suspects.find(z) == Suspects.end()) {
        cout << "Lie" << '\n';
        continue;
      }
      if (Suspects.size() == 1) {
        cout << "Truth" << '\n';
      } else {
        cout << "Not defined" << '\n';
      }
    } else {
      if (Suspects.size() == 1 && Suspects.find(z) != Suspects.end()) {
        cout << "Lie" << '\n';
        continue;
      }
      if (Suspects.find(z) == Suspects.end()) {
        cout << "Truth" << '\n';
        continue;
      } else
        cout << "Not defined" << '\n';
    }
  }
  return 0;
}
