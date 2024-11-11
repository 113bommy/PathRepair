#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

const int IINF = INT_MAX;
const int h = 19;
const int w = 15;

struct Data { 
  int x,y,bitmask,cost;
  bool operator < ( const Data& data ) const { 
    if( cost != data.cost ) return cost < data.cost; 
    if( x != data.x ) return x < data.x;
    if( y != data.y ) return y < data.y;
    if( bitmask != data.bitmask ) return bitmask < data.bitmask;
  }
};

char a[20][20];
//int mindist[1<<20][9];
set<Data> mindist;
int Index[20][20];

bool isValid(int x,int y) { return 0 <= x && x < w && 0 <= y && y < h; }

void compute(){
  int black = 0;
  int sx=-1,sy=-1;
  rep(i,h) rep(j,w) {
    if( a[i][j] == 'X' ) Index[i][j] = black++;
    if( a[i][j] == 'O' ) sx = j, sy = i;
  }
  //rep(i,(1<<black)) rep(j,9) mindist[i][j] = IINF;
  mindist.clear();
  //mindist[(1<<black)-1][4] = 0;
  mindist.insert((Data){sx,sy,(1<<black)-1,0});
  deque<Data> deq;
  deq.push_back((Data){sx,sy,(1<<black)-1,0});
  while( !deq.empty() ){
    Data data = deq.front(); deq.pop_front();
    REP(dx,-1,2){
      REP(dy,-1,2){
        if( dx == 0 && dy == 0 ) continue;
        int nx = data.x + dx, ny = data.y + dy, nbitmask = data.bitmask;
        bool valid = false;
        while( isValid(nx,ny) && ( a[ny][nx] == 'X' && ( data.bitmask & (1<<Index[ny][nx]) ) ) ){
          nbitmask &= ~(1<<Index[ny][nx]);
          nx += dx, ny += dy;
          valid = true;
        }
        if( valid && ( ny >= h || ( ny == h-1 && isValid(nx,ny) ) ) ) {
          //cout << mindist[data.bitmask]+1 << endl;
          cout << data.cost+1 << endl;
          return;
        } else if( !isValid(nx,ny) ) {
          continue;
        }
        if( !valid ) continue;
        //if( mindist[nbitmask] > mindist[data.bitmask] + 1 ) {
        if( !mindist.count((Data){nx,ny,nbitmask,data.cost+1}) ) {
          //mindist[nbitmask] = mindist[data.bitmask] + 1;
          mindist.insert((Data){nx,ny,nbitmask,data.cost+1});
          deq.push_back((Data){nx,ny,nbitmask,data.cost+1});
        }
      }
    }
  }
  puts("-1");
}

int main(){
  rep(i,h) rep(j,w) scanf(" %c",&a[i][j]);
  compute();
  return 0;
}