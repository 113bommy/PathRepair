#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;
typedef pair<P,int>P2;

string s[21];
int h=21,w=17,sx,sy;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={-1,-1,0,1,1,1,0,-1};
bool d[21][19][1<<20];

map<pair<int,int>,int>M1;
map<int,pair<int,int> >M2;
int cnt;

int main(){
  s[0]=s[20]=".................";
  r(i,h-2){
    cin>>s[i+1];
    s[i+1]="."+s[i+1]+".";
  }
  r(i,h)r(j,w)if(s[i][j]=='O'){
    sx=j;
    sy=i;
    s[i][j]='.';
  }else if(s[i][j]=='X'){
    M2[cnt]=P(i,j);
    M1[P(i,j)]=cnt++;
  }
  queue<P2>q;
  d[sy][sx][0]=1;
  q.push(P2(P(sy*1000+sx,0),0));
  while(!q.empty()){
    P2 p=q.front();q.pop();
    int y=p.first.first/1000;
    int x=p.first.first%1000;
    int cost=p.first.second;
    int bit=p.second;
    r(i,8){
      int ny=y+dy[i];
      int nx=x+dx[i];
      int b=bit;
      if(ny<=0||nx<=0||ny>=h||nx>=w-1)continue;
      if(s[ny][nx]=='.')continue;
      if((1<<M1[P(ny,nx)])&b)continue;
      while(s[ny][nx]=='X'){
	int c=M1[P(ny,nx)];
	if((1<<c)&b)break;
	b+=(1<<c);
	ny+=dy[i];
	nx+=dx[i];
      
      if(ny<19&&(nx==0||nx==w-1))continue;
      if(d[ny][nx][b]==1)continue;
      d[ny][nx][b]=1;
      q.push(P2(P(ny*1000+nx,cost+1),b));
      if(ny>=19){
	cout<<cost+1<<endl;
	return 0;
      }
    }
  }
  cout<<-1<<endl;
}

