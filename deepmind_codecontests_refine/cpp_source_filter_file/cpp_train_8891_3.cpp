#include <bits/stdc++.h>
using namespace std;
int cost[200005], n, nrfii[200005], par[200005], snr[200005], impar[200005],
    nivel[200005], poz[200005], prfiu[200005], suma[200005];
struct nr {
  int val, p;
};
nr aint1[3 * 200005], aint2[3 * 200005];
bool viz[200005];
vector<int> L[200005];
inline void Dfs(int nod, int niv) {
  viz[nod] = true;
  nivel[nod] = niv;
  if (niv & 1) {
    impar[++impar[0]] = nod;
    poz[nod] = impar[0];
  } else {
    par[++par[0]] = nod;
    poz[nod] = par[0];
  }
  vector<int>::iterator it;
  for (it = L[nod].begin(); it != L[nod].end(); ++it)
    if (!viz[*it]) {
      if (!prfiu[nod]) prfiu[nod] = *it;
      Dfs(*it, niv + 1);
      snr[nod] += nrfii[*it];
      nrfii[nod] += L[*it].size() + snr[*it] - 1;
      suma[nod] += nrfii[*it];
    }
}
inline void Update(nr aint[], int nod, int st, int dr, int x, int y, int val) {
  if (st == x && y == dr) {
    aint[nod].val += (dr - st + 1) * val;
    aint[nod].p = val;
    return;
  }
  int mij = (st + dr) / 2;
  aint[2 * nod].val += aint[nod].p * (mij - st + 1);
  aint[2 * nod + 1].val += aint[nod].p * (dr - mij);
  aint[2 * nod].p = aint[nod].p;
  aint[2 * nod + 1].p = aint[nod].p;
  aint[nod].p = 0;
  if (y <= mij)
    Update(aint, 2 * nod, st, mij, x, y, val);
  else if (x > mij)
    Update(aint, 2 * nod + 1, mij + 1, dr, x, y, val);
  else {
    Update(aint, 2 * nod, st, mij, x, mij, val);
    Update(aint, 2 * nod + 1, mij + 1, dr, mij + 1, y, val);
  }
}
inline int Query(nr aint[], int nod, int st, int dr, int poz) {
  if (st == dr) return aint[nod].val;
  int mij = (st + dr) / 2;
  aint[2 * nod].val += aint[nod].p * (mij - st + 1);
  aint[2 * nod + 1].val += aint[nod].p * (dr - mij);
  aint[2 * nod].p = aint[nod].p;
  aint[2 * nod + 1].p = aint[nod].p;
  aint[nod].p = 0;
  if (poz <= mij)
    return Query(aint, 2 * nod, st, mij, poz);
  else
    return Query(aint, 2 * nod + 1, mij + 1, dr, poz);
}
int main() {
  int m, x, y, i, tip, k;
  std::ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (i = 1; i <= n; ++i) cin >> cost[i];
  for (i = 1; i < n; ++i) {
    cin >> x >> y;
    L[x].push_back(y);
    L[y].push_back(x);
  }
  Dfs(1, 1);
  for (i = 1; i <= n; ++i)
    if (nivel[i] & 1)
      Update(aint1, 1, 1, impar[0], poz[i], poz[i], cost[i]);
    else
      Update(aint2, 1, 1, par[0], poz[i], poz[i], cost[i]);
  while (m--) {
    cin >> tip >> x;
    if (tip == 1) {
      cin >> y;
      if (nivel[x] & 1) {
        Update(aint1, 1, 1, impar[0], poz[x], poz[x] + nrfii[x], y);
        if (prfiu[x]) {
          k = poz[prfiu[x]] + L[x].size() + suma[x] - 2;
          if (x == 1) ++k;
          Update(aint2, 1, 1, par[0], poz[prfiu[x]], k, -y);
        }
      } else {
        Update(aint2, 1, 1, par[0], poz[x], poz[x] + nrfii[x], y);
        if (prfiu[x]) {
          k = poz[prfiu[x]] + L[x].size() + suma[x] - 2;
          if (x == 1) ++k;
          Update(aint1, 1, 1, impar[0], poz[prfiu[x]], k, -y);
        }
      }
    } else {
      if (nivel[x] & 1)
        cout << Query(aint1, 1, 1, impar[0], poz[x]) << "\n";
      else
        cout << Query(aint2, 1, 1, par[0], poz[x]) << "\n";
    }
  }
  return 0;
}
