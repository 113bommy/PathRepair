#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > nxt[120001];
vector<pair<long long, long long> > S;
int dir[120001];
int lar[120001];
long long macol[120001];
set<pair<int, long long> > sta[120001];
vector<long long> foo[120001];
vector<pair<int, long long> > consi[120001];
int n, m;
void DFS(int u, long long dist) {
  int good = 0;
  for (int i = 0; i < nxt[u].size(); i++) {
    good = 1;
    DFS(nxt[u][i].first, dist + nxt[u][i].second);
  }
  if (!good) {
    lar[u] = u;
    macol[u] = 1;
  } else {
    int best = 0, bz = 0;
    for (int i = 0; i < nxt[u].size(); i++) {
      int nt = nxt[u][i].first;
      int sz = sta[lar[nt]].size();
      if (sz >= bz) {
        bz = sz;
        best = i;
      }
    }
    int bnt = nxt[u][best].first;
    int la = lar[bnt];
    long long cos = macol[bnt];
    long long lcos = cos;
    for (int i = 0; i < nxt[u].size(); i++) {
      int nt = nxt[u][i].first;
      if (nt != bnt) {
        int nlar = lar[nt];
        cos++;
        set<pair<int, long long> >::iterator it;
        for (auto T : sta[nlar]) {
          sta[la].insert(make_pair(T.first, cos));
          consi[u].push_back(make_pair(T.first, cos));
        }
      }
    }
    for (int i = 0; i < consi[u].size(); i++) {
      pair<int, long long> val = consi[u][i];
      set<pair<int, long long> >::iterator it = sta[la].find(val);
      if (it != sta[la].begin()) {
        --it;
        pair<int, long long> val2 = *it;
        if (val2.second <= lcos) {
          S.push_back(make_pair(dist + val.first, dist + val2.first));
        }
        ++it;
      }
      ++it;
      if (it != sta[la].end()) {
        pair<int, long long> val2 = *it;
        if (val2.second != val.second) {
          S.push_back(make_pair(dist + val2.first, dist + val.first));
        }
      }
    }
    if (sta[la].size()) {
      pair<int, long long> val = *(sta[la].begin());
      int tar;
      int bb = lcos;
      if (val.second <= lcos)
        tar = bnt;
      else {
        for (int i = 0; i < nxt[u].size(); i++) {
          if (nxt[u][i].first != bnt) {
            bb++;
            if (bb == val.second) tar = nxt[u][i].first;
          }
        }
      }
      if (dir[u] != tar) {
        S.push_back(make_pair(dist + val.first, 0));
      }
    }
    lar[u] = la;
    macol[u] = cos;
  }
  for (int i = 0; i < foo[u].size(); i++) {
    sta[lar[u]].insert(make_pair(foo[u][i], 1));
  }
}
long long ret1 = -1, ret2;
pair<long long, long long> Q[120001 * 20];
int head;
map<long long, long long> M;
long long find(long long u) {
  if (M.find(u) == M.end()) {
    return u;
  }
  long long t = find(M[u]);
  return (M[u] = t);
}
void commit() {
  if (ret1 != -1) return;
  long long time = Q[1].first;
  for (int i = 1; i <= head; i++) {
    long long lt = Q[i].second + 1;
    long long good = find(lt);
    if (good > time) {
      ret1 = time;
      return;
    }
    M[good] = good + 1;
  }
  ret2 += head;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n - 1; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    nxt[u].push_back(make_pair(v, w));
    dir[u] = v;
  }
  for (int i = 1; i <= m; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    foo[s].push_back(t);
  }
  DFS(1, 0);
  sort(S.begin(), S.end());
  long long last;
  for (int i = 0; i < S.size(); i++) {
    if (i == 0 || S[i].first == last) {
      head++;
    } else {
      commit();
      head = 1;
    }
    Q[head] = S[i];
    last = S[i].first;
  }
  commit();
  cout << ret1 << " " << ret2 << endl;
}
