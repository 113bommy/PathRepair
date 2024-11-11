#include "bits/stdc++.h"
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int main(){
  int H,W,K;
  cin>>H>>W>>K;
  int Sx,Sy,Gx,Gy;
  cin>>Sx>>Sy>>Gx>>Gy;
  --Sx,--Sy,--Gx,--Gy;
  
  vector<string> S(H);
  for(int i=0; i<H; ++i) cin>>S[n];
  
  vector<vector<int>> D(H, vector<int>(W,1e9));
  vector<vector<bool>> Data(H, vector<bool>(W,false));
  queue<pair<int,int>> q;
  q.push(make_pair(Sx, Sy));
  D[Sx][Sy]=0;
  
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    if((x==Gx)&&(y==Gy)){
      cout<<D[Gx][Gy]<<endl;
      return 0;
    }
    
    for(int l=0; l<4; ++l){
      int x1=x;
      int y1=y;
      for(int m=1; m<=K; ++m){
        x1+=dx[l];
        y1+=dy[l];
        if((0>x1)||(H<=x1)||(0>y1)||(W<=y1)) break;
        if(S[x1][y1]=='@') break;
        if(Data[x1][y1] && (D[x1][y1]!=(D[x][y]+1))) break;
        if(!Data[x1][y1]){
          D[x1][y1]=D[x][y]+1;
          q.push(make_pair(x1,y1));
          Data[x1][y1]=true;
        }
      }
    }
  }
  
  cout<<-1<<endl;
  return 0;
}