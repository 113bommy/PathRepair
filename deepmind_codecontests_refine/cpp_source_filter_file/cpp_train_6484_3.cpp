#include <bits/stdc++.h>
using namespace std;
const int offset = 2;
const int body_dim = 502;
const int body_space = 260000;
int ONI[body_space];
int comp_cnt;
int pHole_comp_cnt;
int n;
int CNI[body_space];
int conPairs;
vector<int> neighbours[body_space];
set<int> risky_healthy;
bool infected[body_space];
bool vis[body_space];
bool cyclicInfection;
int mapToAdress(int a, int b) { return a * body_dim + b; }
void attemptToSpreadState(int a, int b) {
  infected[a] = 1;
  for (int x : neighbours[a]) {
    CNI[x]++;
    ONI[x] += b;
    if (CNI[x] > 1) {
      risky_healthy.insert(x);
    }
  }
}
void dfs(int a) {
  vis[a] = true;
  int CNI = 0;
  for (int x : neighbours[a]) {
    if (infected[x]) {
      if (!vis[x]) {
        dfs(x);
      } else {
        CNI++;
      }
    }
  }
  if (CNI > 1) {
    cyclicInfection = true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i < body_dim; i++) {
    for (int j = 1; j < body_dim; j++) {
      int x = mapToAdress(i, j);
      neighbours[x].push_back(mapToAdress(i - 1, j));
      neighbours[x].push_back(mapToAdress(i + 1, j));
      if (i & 1) {
        neighbours[x].push_back(mapToAdress(i - 1, j + 1));
      } else {
        neighbours[x].push_back(mapToAdress(i + 1, j - 1));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    a += offset, b += offset;
    attemptToSpreadState(mapToAdress(a, b), 1);
  }
  for (int i = 1; i < body_space; i++) {
    for (int j : neighbours[i]) {
      if (infected[i] != infected[j]) {
        conPairs++;
      }
    }
  }
  conPairs >>= 1;
  while (!risky_healthy.empty()) {
    int id = *risky_healthy.begin();
    risky_healthy.erase(risky_healthy.begin());
    if (!infected[id]) {
      attemptToSpreadState(id, 0);
    }
  }
  for (int i = 0; i < body_space; i++) {
    if (!vis[i] && infected[i]) {
      dfs(i);
      comp_cnt++;
    }
  }
  for (int i = 0; i < body_space; i++) {
    if (ONI[i] == 3) {
      int sum = 0;
      for (int j = 0; j < 3; j++) {
        int x = neighbours[i][j];
        sum += ONI[x];
        for (int body_space = 0; body_space < 3; body_space++) {
          int y = neighbours[x][body_space];
          sum += infected[y];
        }
      }
      if (sum == 3) {
        pHole_comp_cnt++;
      }
    }
  }
  if (cyclicInfection) {
    cout << "SICK\n";
  } else {
    cout << "RECOVERED\n";
    cout << conPairs - 2 * (comp_cnt + pHole_comp_cnt);
  }
  return 0;
}
