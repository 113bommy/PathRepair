#include<bits/stdc++.h>
using namespace std;
typedef long long int64;


int height[7][7];
int field[7][7][7];
int n, m;
bool IsEnd(bool color) {
  static const int dx[] = { 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1};
  static const int dy[] = { 0, 1, 0, 1,-1, 0, 0, 1, 1, 1, 1,-1,-1};
  static const int dz[] = { 0, 0, 1, 0, 0, 1,-1, 1,-1, 1,-1, 1,-1};
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        for(int l = 0; l < 13; l++) {
          int x = i, y = j, z = k;
          int cnt = 0;
          while(0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n && field[y][x][z] == color) {
            x += dx[l];
            y += dy[l];
            z += dz[l];
            ++cnt;
          }
          if(cnt >= m) return(true);
        }
      }
    }
  }
  return(false);
}

int main() {
  int p;
  int x[7 * 7 * 7], y[7 * 7 * 7];

  while(cin >> n >> m >> p, n){ 
    fill_n(*height, 7 * 7, 0);
    fill_n(**field, 7 * 7 * 7, -1);
    for(int i = 0; i < p; i++) {
      cin >> x[i] >> y[i];
      --x[i], --y[i];
    }
    bool color = false;
    bool printed = false;
    for(int i = 0; i < p; i++, color = !color) {
      field[y[i]][x[i]][height[y[i]][x[i]]] = color;
      ++height[y[i]][x[i]];
      if(IsEnd(color)) {
        printed = true;
        cout << (color ? "White " : "Black ") << i + 1 << endl;
        break;
      }
    }
    if(!printed) cout << "Draw" << endl;
  }
}