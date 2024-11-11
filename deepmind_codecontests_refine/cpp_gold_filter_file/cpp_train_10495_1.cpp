#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n,h,w;
string fi[405];
bool vis[405][405];
int p[] ={1,0,-1,0};
int q[] ={0,1,0,-1};

LL bfs(int x, int y){
vis[x][y] = 1;
LL bl, wh;
bl=wh=0LL;
queue<int> qx,qy;
qx.push(x);
qy.push(y);
while(!qx.empty()){
int nx=qx.front(); qx.pop();
int ny=qy.front(); qy.pop();
if(fi[nx][ny] == '#') bl++;
else wh++;
for(int i=0;i<4;i++){
int cx = nx+p[i];
int cy = ny+q[i];
if(cx<0 || cx >=h || cy<0 || cy>= w || vis[cx][cy] || fi[cx][cy] == fi[nx][ny]) continue;
vis[cx][cy] = 1;
qx.push(cx);
qy.push(cy);
}
}
return bl*wh;
}

int main(){
cin>>h>>w;
for(int i=0;i<h;i++) cin >> fi[i];
LL ans = 0LL;
for(int i=0;i<h;i++)
for(int j=0;j<w;j++)
if(!vis[i][j]) ans+= bfs(i,j);
printf("%lld\n",ans);
return 0;
}
