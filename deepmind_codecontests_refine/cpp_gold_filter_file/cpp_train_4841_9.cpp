#include <bits/stdc++.h>
using namespace std;
int absolut(int x) {
  if (x < 0) return -x;
  return x;
}
const int limite = 500000;
int n, m;
set<int> c[limite];
set<int> aparece[limite];
map<int, int> aparicion[limite];
int positivo[limite];
int negativo[limite];
int asignado[limite];
int asignacion[limite];
queue<int> q;
void asignar(int v, int val) {
  if (asignado[v]) return;
  asignado[v] = 1;
  asignacion[v] = val;
  for (set<int>::iterator it = aparece[v].begin(); it != aparece[v].end();
       it++) {
    int ic = *it;
    set<int> &s = c[ic];
    bool eliminar = false;
    for (set<int>::iterator its = s.begin(); its != s.end(); its++) {
      int x = *its;
      if (absolut(x) == v) {
        eliminar = val == (x > 0);
        break;
      }
    }
    if (eliminar) {
      for (set<int>::iterator its = s.begin(); its != s.end(); its++) {
        int x = *its;
        if (absolut(x) != v) {
          aparece[absolut(x)].erase(ic);
          q.push(absolut(x));
        }
      }
      s = set<int>();
    } else {
      s.erase(v);
      s.erase(-v);
      if (int(s.size()) == 1) {
        int x = *(s.begin());
        q.push(absolut(x));
      }
    }
  }
  aparece[v] = set<int>();
}
int main() {
  ios::sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      c[i].insert(x);
      aparece[absolut(x)].insert(i);
      positivo[absolut(x)] += x > 0;
      negativo[absolut(x)] += x < 0;
      aparicion[absolut(x)][i] = x > 0;
      if (k == 1) q.push(absolut(x));
    }
  }
  for (int i = 1; i <= n; i++)
    if (int(aparece[i].size()) == 1 or positivo[i] == 0 or negativo[i] == 0)
      q.push(i);
  int ic = 0;
  while (ic < m or not q.empty()) {
    if (not q.empty()) {
      int v = q.front();
      q.pop();
      if (int(aparece[v].size()) == 0) {
      } else if (int(aparece[v].size()) == 1) {
        int ic = *(aparece[v].begin());
        int val = aparicion[v][ic];
        asignar(v, val);
      } else if (positivo[v] == 0) {
        asignar(v, 0);
      } else if (negativo[v] == 0) {
        asignar(v, 1);
      } else {
        set<int>::iterator it = aparece[v].begin();
        int ic0 = *it;
        it++;
        int ic1 = *it;
        if (int(c[ic0].size()) == 1 and int(c[ic1].size()) == 1) {
          cout << "NO" << endl;
          exit(0);
        }
        if (int(c[ic0].size()) == 1) {
          asignar(v, aparicion[v][ic0]);
        } else {
          asignar(v, aparicion[v][ic1]);
        }
      }
    } else if (int(c[ic].size()) > 0) {
      int x = *(c[ic].begin());
      asignar(absolut(x), x > 0);
      ic++;
    } else
      ic++;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << asignacion[i];
  cout << endl;
}
