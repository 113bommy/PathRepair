#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m;
int ha(int x,int y){
	return x*m+y;
}
int judge(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && mp[x][y]=='.'){
		return 1;
	}
	return 0;
}
queue<int> q,qq;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",mp[i]);
		for(int j=0;j<m;j++){
			if(mp[i][j]=='#'){
				q.push(ha(i,j));
				qq.push(1);
			}
		}
	}
	int ans=0;
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		int x=tmp/m,y=tmp%m;
		int th=qq.front();
		qq.pop();
		ans=th;
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(judge(tx,ty)){
				mp[tx][ty]='#';
				q.push(ha(tx,ty));
				qq.push(th+1);
			}
		}
	}
	printf("%d\n",ans-1);
	return 0;
}
