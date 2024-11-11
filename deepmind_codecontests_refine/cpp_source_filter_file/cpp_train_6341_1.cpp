#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef pair<P, P> PP;

int w, h;
char s[66][33];

int dx[] = {1, 1, 1, 1, 1, 2, 2, 2, 3};
int dy[] = {-2, -1, 0, 1, 2, -1, 0, 1, 0};

int mincost[2][66][33];

const int inf = 1 << 25;

int dijkstra()
{
  for(int i = 0; i < 66; i++) {
    for(int j = 0; j < 33 j++) {
      mincost[0][i][j] = inf;
      mincost[1][i][j] = inf;
    }
  }
  priority_queue<PP, vector<PP>, greater<PP> > que;  
  for(int i = 0; i < w; i++) {
    if(s[h-1][i] == 'S') {
      que.push(PP(P(0, 0), P(i, h-1))); mincost[0][h-1][i] = 0;
      que.push(PP(P(0, 1), P(i, h-1))); mincost[1][h-1][i] = 0;
    }
  }
  while(!que.empty()) {
    PP p = que.top(); que.pop();
    int c = p.first.first, lr = p.first.second;
    int x = p.second.first, y = p.second.second;
    if(s[y][x] == 'T') return c;
    if(mincost[lr][y][x] < c) continue;
    for(int i = 0; i < 9; i++) {
      int nx = x + (lr ? dx[i] : -dx[i]), ny = y + dy[i];
      if(0 <= nx && nx < w && 0 <= ny && ny < h && s[ny][nx] != 'X') {
	int d = isdigit(s[ny][nx]) ? s[ny][nx]-'0' : 0;
	if(c + d < mincost[(lr+1)%2][ny][nx]) {
	  mincost[(lr+1)%2][ny][nx] = c + d;
	  que.push(PP(P(c + d, (lr+1)%2), P(nx, ny)));
	}
      }
    }
  }
  return -1;
}

int main()
{
  while(cin >> w >> h, w || h) {
    memset(s, 0, sizeof(s));
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) cin >> s[i][j];
    }
    cout << dijkstra() << endl;
  }
  return 0;
}