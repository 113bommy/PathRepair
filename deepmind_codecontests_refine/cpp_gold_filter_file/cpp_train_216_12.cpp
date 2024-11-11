#include <bits/stdc++.h>
using namespace std;
struct item {
  string type;
  string name;
  int atk, def, orb;
  int sz;
  set<string> residents;
};
struct resident {
  string name;
  string type;
  int power;
  string init;
  bool used;
};
item s[111];
resident r[1111];
struct Compare {
  char x;
  Compare(const char x) : x(x) {}
  bool operator()(const item &a, const item &b) const {
    if (a.type == b.type) {
      if (a.type[0] == 'w') return a.atk > b.atk;
      if (a.type[0] == 'a') return a.def > b.def;
      return a.orb > b.orb;
    }
    if (a.type[0] == x) return true;
    if (b.type[0] == x) return false;
    return a.name < b.name;
  }
};
struct CompareR {
  char x;
  explicit CompareR(const char x) : x(x) {}
  bool operator()(const resident &a, const resident &b) const {
    if (a.type == b.type) {
      return a.power > b.power;
    }
    if (a.type[0] == x) return true;
    if (b.type[0] == x) return false;
    return a.name < b.name;
  }
};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i].name >> s[i].type >> s[i].atk >> s[i].def >> s[i].orb >>
        s[i].sz;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> r[i].name >> r[i].type >> r[i].power >> r[i].init;
    if (r[i].type[0] == 'g')
      r[i].type = "weapon";
    else if (r[i].type[0] == 's')
      r[i].type = "armor";
    else if (r[i].type[0] == 'p')
      r[i].type = "orb";
    r[i].used = false;
  }
  int sizes = 0;
  for (int i = 0; i < n; i++) {
    sizes += s[i].sz;
  }
  if (sizes == m) {
    for (int i = 0; i < m; i++) {
      for (int u = 0; u < n; u++) {
        if (r[i].init == s[u].name) {
          if (s[u].type == r[i].type) {
            if (s[u].type[0] == 'w') {
              s[u].atk += r[i].power;
            } else if (s[u].type[0] == 'a') {
              s[u].def += r[i].power;
            } else if (s[u].type[0] == 'o') {
              s[u].orb += r[i].power;
            }
          }
          s[u].residents.insert(r[i].name);
        }
      }
    }
  } else {
    sort(r, r + m, CompareR('w'));
    int can = -1;
    for (int u = 0;; u++) {
      if (r[u].type[0] != 'w') break;
      ++can;
    }
    for (int i = 0; i < n; i++) {
      if (s[i].type[0] == 'w') {
        for (int u = 0; u <= min(can, s[i].sz - 1); u++) {
          s[i].atk += r[u].power;
          s[i].residents.insert(r[u].name);
          r[u].used = true;
        }
      }
    }
    sort(r, r + m, CompareR('a'));
    can = -1;
    for (int u = 0;; u++) {
      if (r[u].type[0] != 'a') break;
      ++can;
    }
    for (int i = 0; i < n; i++) {
      if (s[i].type[0] == 'a') {
        for (int u = 0; u <= min(can, s[i].sz - 1); u++) {
          s[i].def += r[u].power;
          s[i].residents.insert(r[u].name);
          r[u].used = true;
        }
      }
    }
    sort(r, r + m, CompareR('o'));
    can = -1;
    for (int u = 0;; u++) {
      if (r[u].type[0] != 'o') break;
      ++can;
    }
    for (int i = 0; i < n; i++) {
      if (s[i].type[0] == 'o') {
        for (int u = 0; u <= min(can, s[i].sz - 1); u++) {
          s[i].orb += r[u].power;
          s[i].residents.insert(r[u].name);
          r[u].used = true;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      if (r[i].used == false) {
        for (int u = 0; u < n; u++) {
          if (s[u].residents.size() < s[u].sz) {
            s[u].residents.insert(r[i].name);
            break;
          }
        }
      }
    }
  }
  sort(s, s + n, Compare('w'));
  cout << s[0].name << ' ' << s[0].residents.size();
  for (set<string>::iterator it = s[0].residents.begin();
       it != s[0].residents.end(); ++it)
    cout << ' ' << *it;
  cout << endl;
  sort(s, s + n, Compare('a'));
  cout << s[0].name << ' ' << s[0].residents.size();
  for (set<string>::iterator it = s[0].residents.begin();
       it != s[0].residents.end(); ++it)
    cout << ' ' << *it;
  cout << endl;
  sort(s, s + n, Compare('o'));
  cout << s[0].name << ' ' << s[0].residents.size();
  for (set<string>::iterator it = s[0].residents.begin();
       it != s[0].residents.end(); ++it)
    cout << ' ' << *it;
  cout << endl;
  return 0;
}
