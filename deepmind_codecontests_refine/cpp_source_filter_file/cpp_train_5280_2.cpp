#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ListaAdiacenta;
vector<bool> beenThere(100016);
vector<int> parinte(100016), disc(100016);
vector<int> DP(100016);
int N;
void read() {
  ifstream f("date.in");
  cin >> N;
  ListaAdiacenta.assign(N + 1, vector<int>());
  for (int i = 0; i < N - 1; ++i) {
    int x, y;
    cin >> x >> y;
    ListaAdiacenta[x].push_back(y);
    ListaAdiacenta[y].push_back(x);
  }
}
void DFS(int nod) {
  beenThere[nod] = true;
  int resultSum = 0;
  for (auto &it : ListaAdiacenta[nod]) {
    if (!beenThere[it]) DFS(it), resultSum += DP[it];
  }
  DP[nod] += resultSum;
}
int cnt;
void IS_BRIDGE(int A, int B) {
  if (DP[B] % 2 == 0) {
    if ((DP[1] - DP[B]) % 2 == 0) cnt++;
  }
}
int moment;
void Punte(int curent, int p = -1) {
  beenThere[curent] = true;
  parinte[curent] = disc[curent] = ++moment;
  for (auto &vecin : ListaAdiacenta[curent]) {
    if (vecin == p) continue;
    if (beenThere[vecin])
      parinte[curent] = min(parinte[curent], disc[vecin]);
    else {
      Punte(vecin, curent);
      parinte[curent] = min(parinte[curent], parinte[vecin]);
      if (parinte[vecin] >= disc[curent]) IS_BRIDGE(curent, vecin);
    }
  }
}
int main() {
  read();
  DP.assign(N + 1, 1);
  DFS(1);
  beenThere.assign(N + 1, false);
  Punte(1, -1);
  if (cnt != 0)
    cout << cnt;
  else
    cout << -1;
  return 0;
}
