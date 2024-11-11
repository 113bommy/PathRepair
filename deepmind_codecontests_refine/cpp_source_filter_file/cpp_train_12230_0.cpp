#include <bits/stdc++.h>
using namespace std;
bool debug;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
struct wezel {
  int lewy;
  int prawy;
  wezel(int l = -1, int p = -1) : lewy(l), prawy(p) {}
};
wezel d[nax];
int n, c, czas, a, b;
int najwi[nax], najmi[nax];
char t[1000];
vector<int> vl[nax], vp[nax];
bool mozna = true;
void swag(int x, int p) {
  int najw = -1;
  int najm = p + 1;
  bool zle = false;
  if (x > n) return;
  if (x == p) {
    if (!vl[x].empty() || !vp[x].empty()) mozna = false;
    return;
  }
  for (auto i : vl[x]) {
    najw = max(najw, najwi[i]);
    if (najmi[i] < czas || najwi[i] > p) zle = true;
  }
  for (int i = x + 1; i <= najw; ++i) {
    najw = max(najw, najwi[i]);
  }
  for (auto i : vp[x]) {
    najm = min(najm, najmi[i]);
    if (najmi[i] < czas || najwi[i] > p) zle = true;
  }
  if (najw >= najm || zle) {
    mozna = false;
    return;
  }
  if (najw != -1) {
    ++czas;
    d[czas] = wezel(-1, -1);
    d[x].lewy = czas;
    swag(czas, najw);
  }
  if (czas < p) {
    ++czas;
    d[czas] = wezel(-1, -1);
    d[x].prawy = czas;
    swag(czas, p);
  }
}
void inorder(int x) {
  if (d[x].lewy != -1) inorder(d[x].lewy);
  printf("%d ", x);
  if (d[x].prawy != -1) inorder(d[x].prawy);
}
int main(int argc, char* argv[]) {
  debug = argc > 1;
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; ++i) najwi[i] = najmi[i] = i;
  for (int i = 0; i <= (c)-1; ++i) {
    scanf("%d %d %s", &a, &b, t);
    if (b < a) {
      puts("IMPOSSIBLE");
      return 0;
    }
    if (b > a) {
      if (t[0] == 'L')
        vl[a].push_back(b);
      else
        vp[a].push_back(b);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto j : vl[i]) najwi[i] = max(najwi[i], najwi[j]);
    for (auto j : vp[i]) najwi[i] = max(najwi[i], najwi[j]);
  }
  czas = 1;
  d[1] = wezel(-1, -1);
  swag(1, n);
  if (mozna) {
    inorder(1);
    puts("");
  } else
    puts("IMPOSSIBLE");
  return 0;
}
