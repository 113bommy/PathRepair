#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  char g[52][53];
  fill(g[0],g[52],'#');
  int y,x,d;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin>>g[i][j];
      if(g[i][j]=='^'){
	d=0;
	y=i;
	x=j;
      }else if(g[i][j]=='>'){
	d=1;
	y=i;
	x=j;
      }else if(g[i][j]=='v'){
	d=2;
	y=i;
	x=j;
      }else if(g[i][j]=='<'){
	d=3;
	y=i;
	x=j;
      }
    }
  }
  bool u[52][52][4]={};
  for(;;){
    if(u[y][x][d]++)break;
    if(g[y][x]=='G')break;
    const static int dy[]={-1,0,1,0};
    const static int dx[]={0,1,0,-1};
    const static int rdy[]={-1,1,1,-1};
    const static int rdx[]={1,1,-1,-1};
    int ny=y+dy[d];
    int nx=x+dx[d];
    int ry=y+rdy[d];
    int rx=x+rdx[d];
    if(g[ny][nx]=='#'){
      d=(d+3)%4;
    }else if(g[ry][rx]=='#'){
      y=ny;
      x=nx;
    }else{
      u[ny][nx][d]=true;
      y=dy;
      x=dx;
      if(g[ny][nx]=='G')break;
      y=ry;
      x=rx;
      d=(d+1)%4;
    }
  }
  int ans=0;
  if(g[y][x]=='G'){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
	ans+=find(u[i][j],u[i][j+1],true)!=u[i][j+1];
      }
    }
  }else{
    ans=-1;
  }
  cout<<ans<<endl;
}