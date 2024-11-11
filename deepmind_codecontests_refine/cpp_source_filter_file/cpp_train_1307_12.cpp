#include <bits/stdc++.h>
using namespace std;
map<string, bool> used;
vector<string> vs[60];
vector<string> sp;
int jx1, jy1, jx2, jy2;
int px1, py1, px2, py2;
int n, m, cnt = 0;
string make_str(char a, char b) {
  string s;
  s.push_back(a);
  s.push_back(b);
  return s;
}
void init() {
  char q[] = {'T', 'Q', 'K', 'A'};
  for (int i = 2; i <= 9; i++) {
    char ch = i + '0';
    sp.push_back(make_str(ch, 'C'));
    sp.push_back(make_str(ch, 'D'));
    sp.push_back(make_str(ch, 'H'));
    sp.push_back(make_str(ch, 'S'));
  }
  for (int i = 0; i < 4; i++) {
    char ch = q[i];
    sp.push_back(make_str(ch, 'C'));
    sp.push_back(make_str(ch, 'D'));
    sp.push_back(make_str(ch, 'H'));
    sp.push_back(make_str(ch, 'S'));
  }
}
bool is_clear(int x, int y) {
  map<char, int> mp1;
  map<char, int> mp2;
  for (int i = x; i < x + 3; i++)
    for (int j = y; j < y + 3; j++) {
      string s = vs[i][j];
      char ch = s[0];
      if (!mp1.count(ch))
        mp1[ch] = 1;
      else
        mp1[ch]++;
      ch = s[1];
      if (!mp2.count(ch))
        mp2[ch] = 1;
      else
        mp2[ch]++;
    }
  int k1 = 0, k2 = 0;
  map<char, int>::iterator it;
  for (it = mp1.begin(); it != mp1.end(); it++)
    if ((*it).second > 1) k1++;
  for (it = mp2.begin(); it != mp2.end(); it++)
    if ((*it).second != 9) k2++;
  return (k1 == 0 || k2 == 0);
}
bool is_all_clear() {
  bool f = true;
  for (int x1 = 0; n - x1 >= 3; x1++) {
    for (int y1 = 0; m - y1 >= 3; y1++) {
      for (int x2 = 0; n - x2 >= 3; x2++) {
        for (int y2 = 0; m - y2 >= 3; y2++) {
          if (abs(x1 - x2) < 3 && abs(y1 - y2) < 3) continue;
          if (is_clear(x1, y1) && is_clear(x2, y2)) {
            px1 = x1;
            py1 = y1;
            px2 = x2;
            py2 = y2;
            return true;
          }
        }
      }
    }
  }
  return false;
}
void my_print(int w) {
  if (!w && is_all_clear()) {
    cout << "Solution exists.\n";
    cout << "There are no jokers.\n";
    cout << "Put the first square to (" << px1 + 1 << ", " << py1 + 1 << ")."
         << endl;
    cout << "Put the second square to (" << px2 + 1 << ", " << py2 + 1 << ")."
         << endl;
  } else if (w) {
    if (w == 1) {
      if (jx1 == -1) {
        swap(jx1, jx2);
        swap(jy1, jy2);
      }
      string s = vs[jx1][jy1];
      for (int i = 0; i < sp.size(); i++) {
        if (used.count(sp[i])) continue;
        vs[jx1][jy1] = sp[i];
        if (is_all_clear()) {
          cout << "Solution exists.\n";
          cout << "Replace " << s << " with " << sp[i] << ".\n";
          cout << "Put the first square to (" << px1 + 1 << ", " << py1 + 1
               << ")." << endl;
          cout << "Put the second square to (" << px2 + 1 << ", " << py2 + 1
               << ")." << endl;
          return;
        }
      }
      cout << "No solution.";
    } else {
      string s1 = vs[jx1][jy1];
      string s2 = vs[jx2][jy2];
      for (int i = 0; i < sp.size(); i++) {
        for (int j = 0; j < sp.size(); j++) {
          if (sp[i] == sp[j] || used.count(sp[i]) || used.count(sp[j]))
            continue;
          vs[jx1][jy1] = sp[i];
          vs[jx2][jy2] = sp[j];
          if (is_all_clear()) {
            cout << "Solution exists.\n";
            cout << "Replace J1 with " << sp[i] << " and J2 with " << sp[j]
                 << ".\n";
            cout << "Put the first square to (" << px1 + 1 << ", " << py1 + 1
                 << ")." << endl;
            cout << "Put the second square to (" << px2 + 1 << ", " << py2 + 1
                 << ")." << endl;
            return;
          }
        }
      }
      cout << "No solution.";
    }
  } else
    cout << "No solution.";
}
int main() {
  cin >> n >> m;
  jx1 = jy1 = jx2 = jy2 = -1;
  px1 = py1 = px2 = py2 = -1;
  init();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      string s;
      cin >> s;
      vs[i].push_back(s);
      used[s] = true;
      if (s == "J1") {
        jx1 = i;
        jy1 = j;
        cnt++;
      }
      if (s == "J2") {
        jx2 = i;
        jy2 = j;
        cnt++;
      }
    }
  my_print(cnt);
}
