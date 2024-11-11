#include <bits/stdc++.h>
#define N 51
using namespace std;
int h,w,p=0;
string A,mp[N];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int x,y,dir;
void start();

void Forward(){
  int nx = x+dx[dir],ny = y+dy[dir];
  if(nx>=0&&ny>=0&&nx<w&&ny<h&&mp[ny][nx]!='#') x=nx,y=ny;
}
 
void Back(){
  int nx = x+dx[(dir+2)%4],ny = y+dy[(dir+2)%4];
  if(nx>=0&&ny>=0&&nx<w&&ny<h&&mp[ny][nx]!='#') x=nx,y=ny;
}
 
void getIdx(){
  char ch = A[p];
  int cnt=0;
  while(1){
    if(ch=='{')cnt+=(A[p]=='{')-(A[p]=='}');
    if(ch=='[')cnt+=(A[p]=='[')-(A[p]==']');
    p++;
    if(cnt==0) return;
  } 
}

bool kabe(){
  int nx = x+dx[dir],ny = y+dy[dir];
  if(nx<0||ny<0||nx>=w||ny>=h) return 1;
  return mp[ny][nx] == '#';
}
 
int getCheck(){
  char P = A[p];
  if(P=='N')return dir == 0;
  if(P=='E')return dir == 1;
  if(P=='S')return dir == 2;
  if(P=='W')return dir == 3;
  if(P=='C')return kabe();
  if(P=='T')return 1;
}

void While(){
  int sp = p;
  int f = A[++p]=='~';p+=f;
  int l = p;
  while(1){
    bool con = getCheck();p++;
    if(f) con = !con;
    if(con==0) break;
    start();
    p = l;
  }
  p = sp;
  getIdx();
}
 
void If(){
  assert(A[p]=='[');
  int sp = p;
  int f = A[++p]=='~';p+=f;
  bool con = getCheck();p++;
  if(f) con = !con;
  if(con) start();
  p = sp;
  getIdx();
}
 
int ans,cnt;
void start(){
  while(1){
    if(cnt++>1e7)cout<<-1<<endl,exit(0);
    char P = A[p];
    if(P == '{') While();      
    else if(P == '[')If();
    else if(P =='^'||P=='v'){
      (P=='^')? Forward():Back(),ans++,p++;
      if(mp[y][x] == 'g')cout<<ans<<endl,exit(0);
    }
    else if(P=='<'||P=='>') dir=(P=='>')?(dir+1)%4:(dir+3)%4,ans++,p++;
    else break;
  }
}
 
int main(){
  cin>>h>>w;
  for(int i=0;i<h;i++)cin>>mp[i];
  cin>>A;

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++) if(mp[i][j] == 's')y = i,x = j;

  start();
  cout<<-1<<endl;
  return 0;
}