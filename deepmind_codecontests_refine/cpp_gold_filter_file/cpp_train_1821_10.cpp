#include <bits/stdc++.h>
using namespace std;
const int NMAX = 3 * 1e5 + 2;
const int INF = 1000000005;
struct Aint {
  int value;
  int posInit;
};
Aint aintMin[NMAX * 10], aintMax[NMAX * 10], aint[NMAX * 10];
vector<int> v;
map<int, int> realPos;
vector<pair<pair<int, pair<int, int> >, int> > v2;
int n, m, a[NMAX], b[NMAX], c[NMAX], l[NMAX], r[NMAX];
void updateMin(int node, int st, int dr, int pos, Aint x) {
  if (st == dr) {
    if (aintMin[node].value > x.value) aintMin[node] = x;
  } else {
    int mij = (st + dr) / 2;
    if (pos <= mij)
      updateMin(node * 2, st, mij, pos, x);
    else
      updateMin(node * 2 + 1, mij + 1, dr, pos, x);
    aintMin[node] = aintMin[node * 2];
    if (aintMin[node * 2 + 1].value < aintMin[node].value) {
      aintMin[node] = aintMin[node * 2 + 1];
    }
  }
}
void queryMin(int node, int st, int dr, int A, int B, Aint &ans) {
  if (A <= st && dr <= B) {
    if (ans.value > aintMin[node].value) {
      ans = aintMin[node];
    }
  } else {
    int mij = (st + dr) / 2;
    if (A <= mij) queryMin(node * 2, st, mij, A, B, ans);
    if (B > mij) queryMin(node * 2 + 1, mij + 1, dr, A, B, ans);
  }
}
void updateMax(int node, int st, int dr, int pos, Aint x) {
  if (st == dr) {
    if (aintMax[node].value < x.value) aintMax[node] = x;
  } else {
    int mij = (st + dr) / 2;
    if (pos <= mij)
      updateMax(node * 2, st, mij, pos, x);
    else
      updateMax(node * 2 + 1, mij + 1, dr, pos, x);
    aintMax[node] = aintMax[node * 2];
    if (aintMax[node * 2 + 1].value > aintMax[node].value) {
      aintMax[node] = aintMax[node * 2 + 1];
    }
  }
}
void queryMax(int node, int st, int dr, int A, int B, Aint &ans) {
  if (A <= st && dr <= B) {
    if (ans.value < aintMax[node].value) {
      ans = aintMax[node];
    }
  } else {
    int mij = (st + dr) / 2;
    if (A <= mij) queryMax(node * 2, st, mij, A, B, ans);
    if (B > mij) queryMax(node * 2 + 1, mij + 1, dr, A, B, ans);
  }
}
void update(int node, int st, int dr, int pos, Aint x) {
  if (st == dr) {
    if (aint[node].value < x.value) aint[node] = x;
  } else {
    int mij = (st + dr) / 2;
    if (pos <= mij)
      update(node * 2, st, mij, pos, x);
    else
      update(node * 2 + 1, mij + 1, dr, pos, x);
    aint[node] = aint[node * 2];
    if (aint[node * 2 + 1].value > aint[node].value) {
      aint[node] = aint[node * 2 + 1];
    }
  }
}
void query(int node, int st, int dr, int A, int B, Aint &ans) {
  if (A <= st && dr <= B) {
    if (ans.value < aint[node].value) {
      ans = aint[node];
    }
  } else {
    int mij = (st + dr) / 2;
    if (A <= mij) query(node * 2, st, mij, A, B, ans);
    if (B > mij) query(node * 2 + 1, mij + 1, dr, A, B, ans);
  }
}
char buff[10000];
int poz = 0;
void buf(int &numar) {
  numar = 0;
  while (buff[poz] < '0' || buff[poz] > '9')
    if (++poz == 10000) fread(buff, 1, 10000, stdin), poz = 0;
  while ('0' <= buff[poz] && buff[poz] <= '9') {
    numar = numar * 10 + buff[poz] - '0';
    if (++poz == 10000) fread(buff, 1, 10000, stdin), poz = 0;
  }
}
int main() {
  for (int i = 0; i < NMAX * 10; ++i) {
    aintMin[i].value = INF;
    aintMax[i].value = -INF;
    aint[i].value = 0;
  }
  buf(n);
  buf(m);
  for (int i = 1; i <= n; ++i) {
    buf(l[i]);
    buf(r[i]);
    v.push_back(l[i]);
    v.push_back(r[i]);
    v2.push_back(make_pair(make_pair(l[i], make_pair(r[i], i)), INF));
  }
  for (int i = 1; i <= m; ++i) {
    buf(a[i]);
    buf(b[i]);
    buf(c[i]);
    v.push_back(a[i]);
    v.push_back(b[i]);
    v2.push_back(make_pair(make_pair(a[i], make_pair(b[i], i)), c[i]));
  }
  sort(v2.begin(), v2.end());
  sort(v.begin(), v.end());
  vector<int>::iterator it = unique(v.begin(), v.end());
  v.resize(distance(v.begin(), it));
  for (int i = 0; i < v.size(); ++i) {
    realPos[v[i]] = i + 1;
  }
  int lim = v.size();
  for (int i = 1; i <= n; ++i) {
    Aint x;
    x.value = l[i];
    x.posInit = i;
    updateMin(1, 1, lim, realPos[r[i]], x);
    x.value = r[i];
    x.posInit = i;
    updateMax(1, 1, lim, realPos[l[i]], x);
  }
  long long ans = 0LL;
  pair<int, int> poss;
  for (int i = 1; i <= m; ++i) {
    Aint stanga;
    stanga.value = INF;
    if (realPos[b[i]] <= lim) queryMin(1, 1, lim, realPos[b[i]], lim, stanga);
    Aint dreapta;
    dreapta.value = -INF;
    if (realPos[a[i]] >= 1) queryMax(1, 1, lim, 1, realPos[a[i]], dreapta);
    int xx = b[i] - max(stanga.value, a[i]);
    if (stanga.value != INF && ans < 1LL * c[i] * xx) {
      ans = 1LL * c[i] * xx;
      poss = make_pair(stanga.posInit, i);
    }
    xx = min(b[i], dreapta.value) - a[i];
    if (dreapta.value != -INF && ans < 1LL * c[i] * xx) {
      ans = 1LL * c[i] * xx;
      poss = make_pair(dreapta.posInit, i);
    }
  }
  for (int i = 0; i < v2.size(); ++i) {
    if (v2[i].second == INF) {
      int y = v2[i].first.second.first;
      int x = v2[i].first.first;
      int ceva = v2[i].first.second.second;
      Aint maxx;
      maxx.value = 0;
      if (realPos[y] <= lim) query(1, 1, lim, realPos[y], lim, maxx);
      if (maxx.value != 0) {
        if (ans < 1LL * maxx.value * (y - x)) {
          ans = 1LL * maxx.value * (y - x);
          poss = make_pair(ceva, maxx.posInit);
        }
      }
    } else {
      int x = v2[i].first.first;
      int y = v2[i].first.second.first;
      Aint xx;
      xx.value = v2[i].second;
      xx.posInit = v2[i].first.second.second;
      update(1, 1, lim, realPos[y], xx);
    }
  }
  if (ans == 0) {
    cout << 0 << "\n";
  } else {
    cout << ans << "\n" << poss.first << " " << poss.second << "\n";
  }
  return 0;
}
