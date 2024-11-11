#include <bits/stdc++.h>
using namespace std;
vector<int> gr[100000 + 5];
vector<int> g;
struct dat {
  long long val;
  dat* next;
} * a, *act;
dat* rev[100000 + 5];
long long imax, val[100000 + 5];
int viz[100000 + 5];
void group(long long val, int ind) {
  long long p, i;
  p = 1;
  i = 0;
  while (p <= val) {
    if ((val & p) != 0) {
      gr[i].push_back(ind);
    }
    p = p * 2;
    i++;
  }
  imax = max(imax, i - 1);
}
void adaug(int ind, dat* dupa) {
  act = new dat;
  act->val = ind;
  act->next = dupa->next;
  dupa->next = act;
  rev[ind] = act;
}
int main() {
  long long n, i, nrnev, ind, nrviz, siz;
  cin >> n;
  imax = -1;
  for (i = 1; i <= n; i++) {
    cin >> val[i];
    group(val[i], i);
  }
  if (gr[imax].size() > 1) {
    cout << "No" << '\n';
    return 0;
  }
  a = new dat;
  rev[gr[imax][0]] = a;
  viz[gr[imax][0]] = 1;
  a->val = gr[imax][0];
  a->next = 0;
  act = new dat;
  act->val = 0;
  act->next = a;
  a = act;
  imax--;
  while (imax >= 0) {
    nrnev = 0;
    nrviz = 0;
    g.clear();
    for (i = 0; i < gr[imax].size(); i++) {
      ind = gr[imax][i];
      if (viz[ind] == 0)
        g.push_back(ind);
      else {
        viz[ind] = imax + 1;
        nrviz++;
      }
    }
    nrnev = g.size();
    if (nrnev > nrviz + 1) {
      cout << "No" << '\n';
      return 0;
    }
    if (nrnev > 0) {
      ind = g[g.size() - 1];
      viz[ind] = -1;
      adaug(ind, a);
      g.pop_back();
      if (nrnev > 1) {
        siz = 0;
        act = a->next->next;
        while (!g.empty()) {
          while (viz[act->val] != imax + 1) {
            act = act->next;
          }
          viz[g[g.size() - 1]] = -1;
          adaug(g[g.size() - 1], act);
          g.pop_back();
          act = act->next;
        }
      }
    }
    imax--;
  }
  cout << "Yes" << '\n';
  act = a->next;
  while (act != 0) {
    cout << val[act->val] << ' ';
    act = act->next;
  }
  cout << '\n';
  return 0;
}
