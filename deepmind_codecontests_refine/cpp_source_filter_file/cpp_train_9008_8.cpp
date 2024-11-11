#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
vector<int> arbol[MAXN];
int prof[MAXN];
int sub[MAXN];
double esp[MAXN];
int dfs1(int act, int h) {
  prof[act] = h;
  int cant = 1;
  for (auto it = arbol[act].begin(); it != arbol[act].end(); it++) {
    cant += dfs1(*it, h + 1);
  }
  return sub[act] = cant;
}
void dfs(int act) {
  for (auto it = arbol[act].begin(); it != arbol[act].end(); it++) {
    int h = *it;
    esp[h] = esp[act] + 1.0 + 0.5 * (sub[act] - sub[h]);
    dfs(h);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = (0); i < (n - 1); i++) {
    int padre;
    cin >> padre;
    padre--;
    arbol[padre].push_back(i + 1);
  }
  dfs1(0, 1);
  esp[0] = 1;
  dfs(0);
  for (int i = (0); i < (n); i++) {
    cout << fixed << setprecision(1) << esp[i] << " ";
  }
  cout << "\n";
}
