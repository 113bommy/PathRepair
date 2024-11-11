#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int ind, par;
} Wasd;
typedef struct {
  int tam, ind1, ind2;
} Wesd;
vector<Wasd> comp;
bool all[102];
int p[2];
vector<Wesd> res;
bool operator<(const Wesd &a, const Wesd &b) { return a.tam < b.tam; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  p[0] = n / 2, p[1] = (n + 1) / 2;
  int x;
  Wasd te;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x != 0) {
      x %= 2;
      all[i] = x;
      p[x]--;
      te.ind = i;
      te.par = x;
      comp.push_back(te);
    }
  }
  if (comp.size() == 0) {
    if (n > 1)
      cout << "1";
    else
      cout << "0";
    return 0;
  }
  Wesd ta;
  int d = 0;
  for (int i = 0; i < comp.size() - 1; i++)
    if (comp[i].par == comp[i + 1].par) {
      ta.ind1 = comp[i].ind;
      ta.ind2 = comp[i + 1].ind;
      ta.tam = ta.ind2 - ta.ind1 - 1;
      if (ta.tam > 0) res.push_back(ta);
    } else
      d++;
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++)
    if (p[all[res[i].ind2]] >= res[i].tam) {
      bool z = all[res[i].ind2];
      p[z] -= res[i].tam;
    } else
      d += 2;
  int t = -1;
  bool zt = false;
  if (comp[0].ind > 0) {
    if (p[comp[0].par] < comp[0].ind)
      d++;
    else {
      t = comp[0].ind;
      zt = comp[0].par;
    }
  }
  int tt = comp.size() - 1;
  int tet = -1;
  bool ztet = false;
  if (comp[tt].ind < n - 1) {
    if (p[comp[tt].par] < (n - comp[tt].ind - 1))
      d++;
    else {
      tet = n - comp[tt].ind - 1;
      ztet = comp[tt].par;
    }
  }
  if (t != -1 && tet != -1)
    if (ztet == zt) {
      if (t + tet > p[ztet]) d++;
    }
  cout << d;
  return 0;
}
