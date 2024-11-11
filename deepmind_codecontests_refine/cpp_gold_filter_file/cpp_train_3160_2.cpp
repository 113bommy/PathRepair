#include <bits/stdc++.h>
using namespace std;
map<string, int> mp1;
map<string, int> mp2;
string var[] = {"int", "double", "string", "T"};
vector<int> v[1005];
vector<int> num[1005];
int n, m, k, t, ans, a[1005];
int main() {
  int i, j;
  scanf("%d", &n);
  getchar();
  string s;
  for (i = 1; i <= n; i++) {
    getline(cin, s);
    s.replace(0, s.find("d") + 1, "");
    string s1 = "";
    int pos = 0;
    while (s[pos] != '(' && pos < s.size()) {
      if (s[pos] != ' ') s1 += s[pos];
      pos++;
    }
    if (!mp1[s1]) mp1[s1] = ++t;
    num[mp1[s1]].push_back(i);
    s1 = "";
    for (j = pos; j < s.size(); j++) {
      if (s[j] == ',' || s[j] == ')') {
        for (k = 0; k < 4; k++) {
          if (s1 == var[k]) {
            v[i].push_back(k);
            break;
          }
        }
        s1 = "";
      } else if (s[j] != ' ' && s[j] != '(')
        s1 += s[j];
    }
  }
  scanf("%d", &m);
  getchar();
  for (i = 1; i <= m; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    for (j = 0; j < 4; j++) {
      if (s1 == var[j]) mp2[s2] = j;
    }
  }
  scanf("%d", &k);
  getchar();
  for (i = 1; i <= k; i++) {
    ans = 0;
    getline(cin, s);
    string s1 = "";
    int pos = 0, l = s.size();
    while (s[pos] != '(' && pos < l) {
      if (s[pos] != ' ') s1 += s[pos];
      pos++;
    }
    int x = mp1[s1], cnt = 0;
    string s2 = "";
    for (j = pos; j < l; j++) {
      if (s[j] == ',' || s[j] == ')')
        a[cnt++] = mp2[s2], s2 = "";
      else if (s[j] != ' ' && s[j] != '(')
        s2 += s[j];
    }
    for (j = 0; j < num[x].size(); j++) {
      int y = num[x][j], f = 1;
      if (v[y].size() != cnt) continue;
      for (int q = 0; q < v[y].size(); q++) {
        int z = v[y][q];
        if (z != a[q] && a[i] != 3 && z != 3) {
          f = 0;
          break;
        }
      }
      if (f) ans++;
    }
    printf("%d\n", ans);
    memset(a, 0, sizeof(a));
  }
  return 0;
}
