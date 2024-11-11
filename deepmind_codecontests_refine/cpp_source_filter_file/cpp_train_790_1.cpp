#include <bits/stdc++.h>
using namespace std;
int n, x, y;
string f[100005], g[100005], t[100005];
map<string, int> m1, m2;
int u[100005];
vector<int> v1, v2, r1, r2;
vector<string> p1, p2;
void cty(int k) {
  if (k <= x) {
    if (v1.size()) {
      int o = v1[v1.size() - 1];
      int nex = m2[f[o]];
      v1.pop_back();
      p1.push_back(f[o]), p2.push_back(t[k]);
      u[nex] = 0;
      u[k] = o;
      f[o] = t[k];
      cty(nex);
      return;
    }
    int o = r1[r1.size() - 1];
    r1.pop_back();
    p1.push_back(f[o]), p2.push_back(t[k]);
    u[k] = o;
    f[o] = t[k];
    return;
  }
  if (v2.size()) {
    int o = v2[v2.size() - 1];
    int nex = m1[g[o - x]];
    v2.pop_back();
    p1.push_back(g[o - x]), p2.push_back(t[k]);
    u[nex] = 0;
    u[k] = o;
    g[o - x] = t[k];
    cty(nex);
    return;
  }
  int o = r2[r2.size() - 1];
  r2.pop_back();
  p1.push_back(g[o - x]), p2.push_back(t[k]);
  u[k] = o;
  g[o - x] = t[k];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char c;
    string s = "";
    scanf(" %c", &c);
    while (c != ' ') {
      s += c;
      c = getchar();
    }
    int e;
    scanf("%d", &e);
    if (e)
      f[++x] = s;
    else
      g[++y] = s;
  }
  for (int i = 1; i <= n; i++) {
    string s = "";
    int o = i;
    while (o) {
      char c = '0' + i % 10;
      o /= 10;
      s = c + s;
    }
    t[i] = s;
    if (i <= x)
      m1[s] = i;
    else
      m2[s] = i;
  }
  for (int i = 1; i <= x; i++) {
    if (m1.count(f[i]))
      u[m1[f[i]]] = i;
    else if (m2.count(f[i]))
      u[m2[f[i]]] = i, v1.push_back(i);
    else
      r1.push_back(i);
  }
  for (int i = 1; i <= y; i++) {
    if (m2.count(g[i]))
      u[m2[g[i]]] = i + x;
    else if (m1.count(g[i]))
      u[m1[g[i]]] = i + x, v2.push_back(i + x);
    else
      r2.push_back(i + x);
  }
  for (int i = 1; i <= n; i++)
    if (!u[i]) cty(i);
  for (int i = 1; i <= x; i++) {
    if (u[i] > x) {
      p1.push_back(g[u[i] - x]), p2.push_back("escape");
      g[u[i] - x] = "escape";
      r2.push_back(u[i]);
      vector<int> V;
      for (int j = 0; j < v2.size(); j++)
        if (v2[j] != u[i]) V.push_back(v2[j]);
      v2 = V;
      u[i] = 0;
      cty(i);
    }
  }
  for (int i = x + 1; i <= n; i++) {
    if (u[i] <= x) {
      p1.push_back(f[u[i]]), p2.push_back("escape");
      f[u[i]] = "escape";
      r1.push_back(u[i]);
      vector<int> V;
      for (int j = 0; j < v1.size(); j++)
        if (v1[j] != u[i]) V.push_back(v1[j]);
      v1 = V;
      u[i] = 0;
      cty(i);
    }
  }
  printf("%d\n", p1.size());
  for (int i = 0; i < p1.size(); i++)
    printf("move %s %s\n", p1[i].c_str(), p2[i].c_str());
  return 0;
}
