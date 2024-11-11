#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
vector<int> l, p;
vector<int> Z;
void DodajFU() {
  int nowy = Z.size();
  Z.push_back(nowy);
}
int Find(int a) {
  if (Z[a] == a) return a;
  int fa = Find(Z[a]);
  Z[a] = fa;
  return fa;
}
void Union(int a, int b) {
  int fa = Find(a);
  int fb = Find(b);
  if (a != b) Z[fb] = fa;
}
vector<vector<int> > T;
int lisc, size;
void Stworz(int n) {
  int p = 1;
  while (p < n) p *= 2;
  lisc = p;
  size = 2 * p - 1;
  vector<int> pusty;
  for (int i = 0; i <= size; ++i) T.push_back(pusty);
}
void DodajST(int a, int b, int x) {
  a += lisc;
  b += lisc;
  T[a].push_back(x);
  if (a != b) T[b].push_back(x);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) T[a + 1].push_back(x);
    if (b % 2 == 1) T[b - 1].push_back(x);
    a /= 2;
    b /= 2;
  }
}
void Merge(int a, int b) {
  a = Find(a);
  b = Find(b);
  l[a] = min(l[a], l[b]);
  p[a] = max(p[a], p[b]);
  Union(a, b);
}
void Polacz(int start, int k) {
  int a = start + lisc;
  while (a != 0) {
    vector<int> zb;
    bool jest = false;
    for (int i = 0; i < T[a].size(); ++i) {
      if (M[l[Find(T[a][i])]] == start || M[p[Find(T[a][i])]] == start)
        zb.push_back(T[a][i]);
      else {
        Merge(T[a][i], k);
        jest = true;
      }
    }
    if (jest) zb.push_back(Find(k));
    T[a] = zb;
    a /= 2;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> w;
  vector<vector<int> > oper(n, vector<int>(3));
  for (int i = 0; i < n; ++i) {
    cin >> oper[i][0] >> oper[i][1] >> oper[i][2];
    if (oper[i][0] == 1) {
      w.push_back(oper[i][1]);
      w.push_back(oper[i][2]);
    } else {
      --oper[i][1];
      --oper[i][2];
    }
  }
  sort(w.begin(), w.end());
  int nr = -1;
  for (int i = 0; i < w.size(); ++i) {
    if (i == 0 || w[i] != w[i - 1]) ++nr;
    M[w[i]] = nr;
  }
  Stworz(nr + 1);
  for (int i = 0; i < n; ++i) {
    int a = oper[i][1], b = oper[i][2];
    if (oper[i][0] == 1) {
      l.push_back(a);
      p.push_back(b);
      DodajFU();
      DodajST(M[a], M[b], Z.size() - 1);
      Polacz(M[a], Z.size() - 1);
      Polacz(M[b], Z.size() - 1);
    } else {
      int fa = Find(a), fb = Find(b);
      if (fa == fb || (l[fa] >= l[fb] && p[fa] <= p[fb]))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
