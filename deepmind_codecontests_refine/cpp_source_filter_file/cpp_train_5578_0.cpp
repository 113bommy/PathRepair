#include <bits/stdc++.h>
using namespace std;
int N, K, M;
int edg[101010][6];
int edge(int x, int y) {
  if (x > y) swap(x, y);
  int diff = y - x;
  if (diff > 5) return 0;
  return edg[x][diff];
}
struct cel {
  int h[10];
  int nd[10];
  int nr;
  int st, dr;
  cel() {
    for (int i = 0; i < 10; ++i) {
      h[i] = i;
      nd[i] = 0;
    }
    nr = 0;
  }
};
cel aint[101010 * 4];
int hx[202222];
int nd[202222];
int get(int x) {
  while (hx[x] != x) {
    x = hx[x];
  }
  return x;
}
void unite(int x, int y) {
  if (get(x) == get(y)) return;
  hx[get(x)] = y;
}
int brut(int st, int dr) {
  for (int i = st; i <= dr; ++i) {
    hx[i] = i;
  }
  int ret = (dr - st) + 1;
  for (int i = st; i <= dr; ++i) {
    for (int j = i; j <= dr && j <= i + 5; ++j) {
      if (edge(i, j)) {
        unite(i, j);
        --ret;
      }
    }
  }
  return ret;
}
cel operator+(cel a, cel b) {
  int n1 = (a.dr - a.st) + 1;
  int n2 = (b.dr - b.st) + 1;
  n1 = min(n1, 10);
  n2 = min(n2, 10);
  int n = n1 + n2;
  cel ret;
  ret.st = a.st;
  ret.dr = b.dr;
  ret.nr = a.nr + b.nr;
  for (int i = 0; i < n1; ++i) {
    hx[i] = a.h[i];
    nd[i] = a.nd[i];
  }
  for (int i = 0; i < n2; ++i) {
    hx[i + n1] = b.h[i] + n1;
    nd[i + n1] = b.nd[i];
  }
  for (int i = n1 - 1; i >= 0 && i >= n1 - 5; --i) {
    for (int j = n1; j <= n1 + 4 && j < n; ++j) {
      if (edge(nd[i], nd[j])) {
        if (get(i) != get(j)) {
          --ret.nr;
          unite(i, j);
        }
      }
    }
  }
  for (int i = 0; i < min(5, n); ++i) {
    ret.h[i] = get(i);
    ret.nd[i] = nd[i];
  }
  int toput = min(n1 + n2 - 1, 9);
  for (int j = 0; j < min(5, n); ++j) {
    ret.h[toput] = get(n - j - 1);
    ret.nd[toput] = nd[n - j - 1];
    --toput;
  }
  int nrid = 0;
  map<int, int> h;
  for (int i = 0; i < min(n, 10); ++i) {
    if (h.count(ret.h[i]) == 0) {
      h[ret.h[i]] = nrid++;
    }
    ret.h[i] = h[ret.h[i]];
  }
  return ret;
}
inline void make(int nod, int st, int dr) {
  if (st == dr) {
    aint[nod].nr = 1;
    aint[nod].h[0] = 0;
    aint[nod].nd[0] = st;
    return;
  }
  aint[nod] = aint[2 * nod] + aint[2 * nod + 1];
}
cel calc(int nod, int ist, int idr, int st, int dr) {
  if (st >= ist && idr >= dr) {
    return aint[nod];
  }
  long long mij = (st + dr) / 2;
  if (ist <= mij && idr > mij)
    return calc(nod * 2, ist, idr, st, mij) +
           calc(nod * 2 + 1, ist, idr, mij + 1, dr);
  else if (ist <= mij)
    return calc(nod * 2, ist, idr, st, mij);
  else
    return calc(nod * 2 + 1, ist, idr, mij + 1, dr);
}
void init(int nod, int st, int dr) {
  if (st != dr) {
    int mij = (st + dr) / 2;
    init(2 * nod, st, mij);
    init(2 * nod + 1, mij + 1, dr);
    make(nod, st, dr);
  } else {
    aint[nod].st = st;
    aint[nod].dr = dr;
    aint[nod].nr = 1;
    aint[nod].h[0] = 0;
    aint[nod].nd[0] = st;
  }
}
int x, y;
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> K;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    edg[x][y - x] = 1;
  }
  init(1, 1, N);
  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> x >> y;
    cout << calc(1, x, y, 1, N).nr << "\n";
  }
}
