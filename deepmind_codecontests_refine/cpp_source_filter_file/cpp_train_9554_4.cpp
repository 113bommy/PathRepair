#include<bits/stdc++.h>
using namespace std;
int main() {
  int H, W, M; cin >> H >> W >> M;
  vector<int> R(H), C(W);
  map<pair<int, int>, int> m;
  int mr = 0, mc = 0;
  for (int i = 0; i < M; i++) {
    int r, c; cin >> r >> c; r--, c--;
    mr = max(mr, ++R[r]);
    mc = max(mc, ++C[c]);
    m[{r, c}] = 1;
  }
  vector<int> a, b;
  for (int i = 0; i < H; i++) {
    if (R[i] == mr) a.push_back(i);
  }
  for (int i = 0; i < W; i++) {
    if (C[i] == mc) b.push_back(i);
  }
  for (auto x : a) {
    for (auto y : b) {
      if (m[{x, y}] == 0) {
        cout << mr + mc << endl;
        return 0;
      }
    }
  }
  cout << mr + mc - 1 << endl;
}
}
