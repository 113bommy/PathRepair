#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
long long int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
struct node {
  long long int x, y, col, dir;
};
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int arr[n][m];
  for (long long int il = 0; il < n; il++)
    for (long long int jl = 0; jl < m; jl++) {
      char ch;
      cin >> ch;
      arr[il][jl] = ch - 'A';
    }
  for (long long int il = 0; il < n; il++) {
    for (long long int jl = 0; jl < m; jl++) {
      node nde;
      nde.x = il;
      nde.y = jl;
      nde.col = arr[il][jl];
      nde.dir = 0;
      bool vis[n][m];
      for (long long int zl = 0; zl < n; zl++)
        for (long long int yl = 0; yl < m; yl++) vis[zl][yl] = 0;
      queue<node> q;
      q.push(nde);
      vis[il][jl] = 1;
      while (!q.empty()) {
        node tn = q.front();
        q.pop();
        long long int tnx = tn.x;
        long long int tny = tn.y;
        long long int tnc = tn.col;
        long long int tdir = tn.dir;
        ;
        for (long long int wl = 0; wl < 4; wl++) {
          long long int cdir = 0;
          if (dx[wl] == 1 && (tdir != -1))
            cdir = 1;
          else if (dx[wl] == -1 && (tdir != 1))
            cdir = -1;
          else if (dy[wl] == 1 && (tdir != -2))
            cdir = 2;
          else if (dy[wl] == -1 && (tdir != 2))
            cdir = -2;
          else
            continue;
          long long int ddx = tnx + dx[wl];
          long long int ddy = tny + dy[wl];
          if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m &&
              arr[ddx][ddy] == tnc) {
            if (vis[ddx][ddy]) {
              cout << "Yes\n";
              ;
              ;
              ;
              ;
              return 0;
            }
            vis[ddx][ddy] = 1;
            node nn;
            nn.x = ddx;
            nn.y = ddy;
            nn.col = tnc;
            nn.dir = cdir;
            q.push(nn);
          }
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
