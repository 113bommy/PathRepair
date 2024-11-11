#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
const int MOD = 1000000009;
const int INF = 1000000000;
const long long LINF = 1000000000000000000LL;
map<string, int> mapa;
vector<int> ladj[10000];
vector<string> vs;
char arr[110], *ptr;
int file[10000], folder[10000];
bool vis[10000];
void dfs(int a) {
  int f1 = 0, f2 = 0;
  vis[a] = true;
  for (int i = int(0); i <= int(int((ladj[a]).size()) - 1); i++) {
    int b = ladj[a][i];
    if (!vis[b]) dfs(b), f1 += folder[b], f2 += file[b];
  }
  folder[a] = 1 + f1, file[a] += f2;
}
int main() {
  int x = 0, p, r1 = 0, r2 = 0;
  while (gets(arr)) {
    vs.clear(), p = 0;
    for (ptr = strtok(arr, ":\\"); ptr != NULL; ptr = strtok(NULL, ":\\"))
      vs.push_back(ptr);
    for (int i = int(1); i <= int(int((vs).size()) - 1); i++)
      vs[i] = vs[i - 1] + vs[i];
    for (int i = int(1); i <= int(int((vs).size()) - 2); i++) {
      if (!(mapa.find(vs[i]) != mapa.end()))
        mapa[vs[i]] = ++x, ladj[p].push_back(x);
      p = mapa[vs[i]];
    }
    file[p]++;
  }
  dfs(0);
  for (int i = int(0); i <= int(int((ladj[0]).size()) - 1); i++)
    x = ladj[0][i], r1 = max(r1, folder[x]), r2 = max(r2, file[x]);
  printf("%d %d\n", r1 - 1, r2);
  return 0;
}
