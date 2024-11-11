#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
int vy[6] = {-1, -1, 0, 1, 1, 0};
int vx_0[6] = {0, 1, 1, 1, 0, -1};
int vx_1[6] = {-1, 0, 1, 0, -1, -1};
int W, H;
int b[100][100];
bool checked[100][100];
vector<P> wh;

bool bwb(int y, int x) {
  if(y < 0 || y >= H || x < 0 || x >= W) return false;
  if(checked[y][x] || b[y][x]) return true;
  checked[y][x] = true;
  wh.push_back(P(y,x));
  bool ret = true;
  FOR(i,0,6) {
    int ny = y + vy[i];
    int nx = x + (y % 2 ? vx_1[i] : vx_0[i]);
    ret &= bwb(ny, nx);
  }
  return ret;
}
int calc(int y, int x) {
  int ret = 0;
  FOR(i,0,6) {
    int ny = y + vy[i];
    int nx = x + (y % 2 ? vx_1[i] : vx_0[i]);
    if(ny < 0 || ny >= H || nx < 0 || nx >= W || b[ny][nx] == 0) ret++;
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> W >> H;
  FOR(i,0,H) FOR(j,0,W) cin >> b[i][j];
  FOR(y,0,H) {
    FOR(x,0,W) {
      if(checked[y][x] || b[y][x]) continue;
      wh.clear();
      if(bwb(y, x)) {
        FOR(j,0,wh.size()) {
          b[wh[j].first][wh[j].second] = 1;
        }
      }
    }
  }
  int ans = 0;
  FOR(y,0,H) {
    FOR(x,0,W) {
      if(b[y][x]) ans += calc(y, x);
    }
  }
  cout << ans << endl;
  return 0;
}