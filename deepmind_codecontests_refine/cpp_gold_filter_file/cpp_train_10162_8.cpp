#include <bits/stdc++.h>
bool m1;
FILE *Input = stdin, *Output = stdout;
const int maxn = 1e5 + 5, maxm = 1e5 + 5, maxb = 30;
struct Edge {
  int to, next, dis;
  Edge(){};
  Edge(int ar1, int ar2, int ar3) {
    to = ar1;
    dis = ar2;
    next = ar3;
  }
} Map_List[maxm << 1];
int Numm[maxn], totm, dis[maxn];
bool vis[maxn], vis2[maxn];
struct Linear_Basis {
  int Basis[maxb];
  Linear_Basis() { memset(Basis, 0, sizeof(Basis)); }
  void Insert(int ar1) {
    int now = ar1;
    for (int i = maxb - 1; i >= 0; i--) {
      if (!(now >> i & 1)) continue;
      if (!Basis[i]) {
        Basis[i] = now;
        break;
      } else
        now ^= Basis[i];
    }
  }
  int Query_Min(int ar1 = 0) {
    int now = ar1;
    for (int i = maxb - 1; i >= 0; i--) {
      if (Basis[i]) now = std::min(now, now ^ Basis[i]);
    }
    return now;
  }
} Set;
bool m2;
void Add_Map(int ar1, int ar2, int ar3) {
  Map_List[++totm] = Edge(ar2, ar3, Numm[ar1]);
  Numm[ar1] = totm;
}
void Get_Ring(int ar1) {
  vis[ar1] = vis2[ar1] = 1;
  for (int i = Numm[ar1]; i; i = Map_List[i].next) {
    int hh = Map_List[i].to;
    if (!vis[hh]) {
      dis[hh] = dis[ar1] ^ Map_List[i].dis;
      Get_Ring(hh);
    } else if (vis2[hh])
      Set.Insert(dis[hh] ^ dis[ar1] ^ Map_List[i].dis);
  }
  vis2[ar1] = 0;
}
int main() {
  int n, m;
  fscanf(Input, "%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int h1, h2, h3;
    fscanf(Input, "%d %d %d", &h1, &h2, &h3);
    Add_Map(h1, h2, h3);
    if (h1 != h2) Add_Map(h2, h1, h3);
  }
  Get_Ring(1);
  fprintf(Output, "%d\n", Set.Query_Min(dis[n]));
  fclose(Input);
  fclose(Output);
  return 0;
}
