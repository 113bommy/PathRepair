#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
#define N 4
#define NN 16

static const int dx[4] = {0,-1,0,1};
static const int dy[4] = {1,0,-1,0};
int H[NN][NN];

struct Puzzle
{
  int f[NN],space,MD;
  int cost;

    bool operator < (const Puzzle& p) const {
    for(int i=0; i<NN; i++) {
        if( f[i] == p.f[i] ) continue;
        return f[i] < p.f[i];
    }
    return false;
    }
};

struct State
{
  Puzzle puzzle;
  int estimated;
  bool operator < (const State &s) const{
    return estimated > s.estimated;
  }
};

int getAllMD(Puzzle pz){
    int sum=0;
    for(int i=0; i<NN; i++) {
    if( pz.f[i] == NN ) continue;
    sum += H[i][pz.f[i]-1];
    }
    return sum;
}

int astar(Puzzle s){
  priority_queue<State> PQ;
  s.MD = getAllMD(s);
  s.cost = 0;
  map<Puzzle,bool> V;
  Puzzle u,v;
  State initial;
  initial.puzzle = s;
  initial.estimated = getAllMD(s);
  PQ.push(initial);

  while(!PQ.empty()){
    State st = PQ.top(); PQ.pop();
    u = st.puzzle;
    if( u.MD == 0 ) return u.cost;
    V[u] = true;

    int sx = u.space / N;
    int sy = u.space % N;

    for(int r=0; r<4; r++) {
        int tx = sx + dx[r];
        int ty = sy + dy[r];
        if( tx<0 || ty<0 || tx>=N || ty>=N ) continue;
        v = u;

        v.MD -= H[tx*N+ty][v.f[tx*N+ty]-1];
        v.MD += H[sx*N+sy][v.f[tx*N+ty]-1];

        swap(v.f[sx*N+sy], v.f[tx*N+ty]);
        v.space = tx*N+ty;
        if( !V[v] ) {
        v.cost++;
        State news;
        news.puzzle = v;
        news.estimated = v.cost + v.MD;
        PQ.push(news);
        }
    }
    }
    return -1;
}

int main(){
for(int i = 0; i<NN; i++)
  for(int j =0;j < NN;j++)
    H[i][j] = abs(i / N - j / N) + abs(i % N - j % N);

  Puzzle in;

  for(int i=0;i<NN;i++){
    cin >> in.f[i];
    if(in.f[i] == 0){
      in.f[i] = NN;
      in.space = i;
    }
  }

  cout << astar(in) << endl;
  return 0;
}
