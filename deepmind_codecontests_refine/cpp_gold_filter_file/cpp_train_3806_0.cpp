#include <bits/stdc++.h>
const int kNMax = 1001;
const int kMMax = 10001;
using namespace std;
int Ex[kMMax], Ey[kMMax];
long long Ec[kMMax];
bool Es[kMMax];
vector<int> G[kNMax];
long long dst[kNMax];
queue<int> Q;
bool inQ[kNMax];
inline int neigh(int edge, int vertex) {
  if (Ex[edge] == vertex) return Ey[edge];
  return Ex[edge];
}
int parent[kNMax];
int spfa(int n, int inf, int source, int dest) {
  for (int i = 1; i <= n; ++i) dst[i] = inf;
  dst[source] = 0;
  while (!Q.empty()) Q.pop();
  for (int i = 1; i <= n; ++i) inQ[i] = 0;
  Q.push(source);
  inQ[source] = 1;
  while (!Q.empty()) {
    int nod = Q.front();
    Q.pop();
    inQ[nod] = 0;
    vector<int>::iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
      int target = neigh(*it, nod);
      if (dst[target] > dst[nod] + Ec[*it]) {
        dst[target] = dst[nod] + Ec[*it];
        parent[target] = *it;
        if (inQ[target] == 0) {
          inQ[target] = 1;
          Q.push(target);
        }
      }
    }
  }
  return dst[dest];
}
void print_sol(int m) {
  cout << "YES\n";
  for (int i = 1; i <= m; ++i)
    cout << Ex[i] - 1 << " " << Ey[i] - 1 << " " << Ec[i] << "\n";
}
int main() {
  int n, m, L, s, d;
  int special_cnt = 0;
  cin >> n >> m >> L >> s >> d;
  ++s;
  ++d;
  for (int i = 1; i <= m; ++i) {
    cin >> Ex[i] >> Ey[i] >> Ec[i];
    ++Ex[i];
    ++Ey[i];
    G[Ex[i]].push_back(i);
    G[Ey[i]].push_back(i);
    if (Ec[i] == 0) {
      Es[i] = 1;
      ++special_cnt;
    }
  }
  for (int i = 1; i <= m; ++i)
    if (Es[i] == 1) Ec[i] = L + 1;
  int cost_withot_special = spfa(n, L + 1, s, d);
  if (special_cnt == 0) {
    if (cost_withot_special != L) {
      cout << "NO";
      return 0;
    } else {
      print_sol(m);
      return 0;
    }
  }
  if (cost_withot_special < L) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i <= m; ++i)
    if (Es[i] == 1) Ec[i] = 1;
  int minimal_cost = spfa(n, L + 1, s, d);
  if (minimal_cost > L) {
    cout << "NO";
    return 0;
  }
  while (minimal_cost < L) {
    int nod = d;
    while (nod != s) {
      int edge = parent[nod];
      if (Es[edge]) {
        Ec[edge] += L - minimal_cost;
        break;
      }
      nod = neigh(edge, nod);
    }
    minimal_cost = spfa(n, L + 1, s, d);
  }
  print_sol(m);
  return 0;
}
