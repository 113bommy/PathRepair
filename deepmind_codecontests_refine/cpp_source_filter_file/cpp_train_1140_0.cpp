#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define INF 100
using namespace std;
struct data{
	int x,y,p,q,dir;
	data(){}
	data(int yy,int xx,int dd,int pp,int qq){
		x=xx;
		y=yy;
		p=pp;
		q=qq;
		dir=dd;
	}
	bool operator<(const data &d)const{
		return q>d.q;
	}
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,a;
int fie[101][101];
int dp[101][101][4][11];
int sx,sy,gx,gy;

int dijk(){
	int res=INF;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<=a;l++){
					dp[i][j][k][l]=INF;
				}
			}
		}
	}
	priority_queue<data> que;
	que.push(data(sy,sx,1,0,0));
	dp[sy][sx][1][0]=0;
	while(que.size()){
		data q=que.top();
		que.pop();
		if(dp[q.y][q.x][q.dir][q.p]<q.q)continue;
		if(0<=q.x+dx[q.dir] && q.x+dx[q.dir]<m && 0<=q.y+dy[q.dir] && q.y+dy[q.dir]<n){
			if(fie[q.y+dy[q.dir]][q.x+dx[q.dir]]!=-1 && dp[q.y+dy[q.dir]][q.x+dx[q.dir]][q.dir][q.p]>q.q){
				if(fie[q.y+dy[q.dir]][q.x+dx[q.dir]]==1 && dir==2)continue;
				dp[q.y+dy[q.dir]][q.x+dx[q.dir]][q.dir][q.p]=q.q;
				que.push(data(q.y+dy[q.dir],q.x+dx[q.dir],q.dir,q.p,q.q));
			}
		}
		if(q.p<a){
			int ndir=-1;
			if(q.dir==0)ndir=3;
			if(q.dir==1)ndir=2;
			if(q.dir==2)ndir=1;
			if(q.dir==3)ndir=0;
			if(fie[q.y][q.x]==0 && dp[q.y][q.x][ndir][q.p+1]>q.q){
				dp[q.y][q.x][ndir][q.p+1]=q.q;
				que.push(data(q.y,q.x,ndir,q.p+1,q.q));
			}
		}
		if(q.q<a){
			int ndir=-1;
			if(q.dir==0)ndir=1;
			if(q.dir==1)ndir=0;
			if(q.dir==2)ndir=3;
			if(q.dir==3)ndir=2;
			if(fie[q.y][q.x]==0 && dp[q.y][q.x][ndir][q.p]>q.q+1){
				dp[q.y][q.x][ndir][q.p]=q.q+1;
				que.push(data(q.y,q.x,ndir,q.p,q.q+1));
			}
		}
	}
	for(int i=0;i<=a;i++){
		for(int j=0;j<4;j++){
			res=min(res,dp[gy][gx][j][i]+i);
		}
	}
	return res!=INF?res:-1;
}

int main(void){
	scanf("%d %d %d %d",&n,&m,&a);
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		for(int j=0;j<m;j++){
			if(str[j]=='S')sx=j,sy=i,fie[i][j]=1;
			if(str[j]=='G')gx=j,gy=i,fie[i][j]=2;
			if(str[j]=='#')fie[i][j]=-1;
		}
	}
	printf("%d\n",dijk());
	return 0;
}