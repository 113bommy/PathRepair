#include <bits/stdc++.h>
using namespace std;
int NN, VV, K;
int in[5555];
int X, Y;
vector<int> gr[123457];
int col, PP, timer;
int sec[5005];
int depth[555555];
double pasux;
void dfs(int v, int p = -1) {
  for (auto x : gr[v]) {
    if (x != p) {
      depth[x] = depth[v] + 1;
      dfs(x, v);
    }
  }
}
int am, bm;
int main() {
  cin >> PP;
  for (int i = 0; i < PP - 1; i++) {
    cin >> am >> bm;
    gr[am - 1].push_back(bm - 1);
    gr[bm - 1].push_back(am - 1);
  }
  dfs(0);
  for (int i = 1; i <= PP; i++) pasux += 1. / (depth[i] + 1);
  printf("%.17f", pasux);
  return 0;
}
