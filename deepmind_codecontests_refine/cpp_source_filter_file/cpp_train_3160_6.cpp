#include <bits/stdc++.h>
using namespace std;
struct proc {
  string name;
  string var[10];
};
struct vari {
  string name;
  string x;
};
string s, t, name, varr[10];
proc a[1005];
vari b[1005];
int res, n, m, k, para[1005], p;
bool check;
int main() {
  if (0) {
    freopen("a.inp", "r", stdin);
  };
  scanf("%d\n", &n);
  size_t found;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    found = s.find("void");
    s.erase(0, int(found) + 4);
    while (s[0] == ' ') s.erase(0, 1);
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == ' ' || s[j] == '(') break;
      a[i].name += s[j];
    }
    t = "";
    found = s.find("(");
    for (int j = int(found) + 1; s[j] != ')'; j++) {
      if (s[j] == ',' || s[j] == ' ') continue;
      while (s[j] != ',' && s[j] != ' ' && s[j] != ')') t += s[j], j++;
      para[i]++;
      a[i].var[para[i]] = t;
      t = "";
      if (s[j] == ')') break;
    }
  }
  scanf("%d\n", &m);
  for (int i = 0; i < m; i++) {
    getline(cin, s);
    int j = 0;
    t = "";
    while (s[j] == ' ') j++;
    while (s[j] != ' ') t += s[j], j++;
    b[i].x = t;
    t = "";
    while (s[j] == ' ') j++;
    while (j < s.length() && s[j] != ' ') t += s[j], j++;
    b[i].name = t;
  }
  scanf("%d\n", &k);
  for (int i = 0; i < k; i++) {
    getline(cin, s);
    int j = 0;
    while (s[j] == ' ') j++;
    t = "";
    while (s[j] != ' ' && s[j] != '(') t += s[j], j++;
    name = t;
    while (s[j] != '(') j++;
    j++;
    t = "";
    p = 0;
    for (; s[j] != ')'; j++) {
      if (s[j] == ' ' || s[j] == ',') continue;
      while (s[j] != ' ' && s[j] != ',' && s[j] != ')') t += s[j], j++;
      check = false;
      for (int x = 0; x < m; x++)
        if (b[x].name == t) {
          t = b[x].x;
          check = true;
          break;
        }
      if (!check) break;
      p++;
      varr[p] = t;
      t = "";
      if (s[j] == ')') break;
    }
    if (!check) {
      printf("0\n");
      continue;
    }
    res = 0;
    for (int x = 0; x < n; x++) {
      if (para[x] != p || a[x].name != name) continue;
      check = true;
      for (int y = 0; y < p; y++) {
        if (a[x].var[y][0] == 'T') continue;
        if (a[x].var[y][0] != varr[y][0]) {
          check = false;
          break;
        }
      }
      if (check) res++;
    }
    printf("%d\n", res);
  }
}
