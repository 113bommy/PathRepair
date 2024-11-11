#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct point{
	int x;
	int y;
	int d;
	point (int a,int b,int c){
		x=a;
		y=b;
		d=c;
	}
};

queue <point> q;
int n,m,a[55][55],s,move[4][2]={1,0,0,1,-1,0,0,-1};
bool v[55][55];

int main(){
	char ch;
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			cin>>ch;
			if (ch=='.'){
				s++;
				a[i][j]=0;
			}
			else{
				a[i][j]=1;
			}
		}
	}
	point p(1,1,1);
	q.push(p);
	v[1][1]=true;
	while (!q.empty()){
		int X=q.front().x,Y=q.front().y,D=q.front().d,xx,yy;
		for (i=0;i<4;i++){
			xx=X+move[i][0];
			yy=Y+move[i][1];
			if (xx>=1 && xx<=n && yy>=1 && yy<=m){
				if (!v[xx][yy] && a[xx][yy]==0){
					point np(xx,yy,D+1);
					q.push(np);
					v[xx][yy]=true;
					if (xx==n && yy==m){
						printf("%d",s-D-1);
						return 0;
					}
				}
			}
		}
		q.pop();
	}
	printf("-1");
	return 0;
}