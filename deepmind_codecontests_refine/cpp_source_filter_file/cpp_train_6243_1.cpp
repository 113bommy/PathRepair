#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P;

#define INF 1000000

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[1100][1100];
char store[1100][1100];

bool bfs(int w,int h,int sy,int sx,int gy,int gx){
	queue<P> que;
	d[sy][sx]=0;
	que.push(P(sy,sx));
	
	while(que.size()){
		P p=que.front();que.pop();
		if(p.first==gy&&p.second==gx) break;
	
		for(int i=0;i<4;i++){
			int ny=p.first+dy[i],nx=p.second+dx[i];
			if(ny>=0 && nx>=0 && ny<h && nx<w && store[ny][nx]!='#' && d[ny][nx]==INF){
				d[ny][nx]=d[p.first][p.second]+1;
				que.push(P(ny,nx));
			}
		}
	}
	
	return d[gy][gx]!=INF;
}

int main(){
	int w,h,n;
	int gx,gy;
	bool flag=false;
	P open[1100];
	cin>>w>>h;
	
	/*for(int i=0;i<1100;i++){
		for(int j=0;j<1100;j++){
			store[i][j]='#';
		}
	}*/
	
	for(int i=0;i<1100;i++){
		for(int j=0;j<1100;j++){
			d[i][j]=INF;
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>store[i][j];
			if(store[i][j]=='t'){
				gx=j;gy=i;
			}
		}
	}
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		open[i]=P(y,x);
	}
	
	for(int i=0;i<=n;i++){
		if(i>0){
			store[open[i].first][open[i].second]='.';
			for(int j=0;j<4;j++){
				int ny=open[i]+dy[j],nx=open[i].second+dx[j]
				if(ny=>0 && nx>=0 && ny<h && nx<w && d[ny][nx]!=INF) flag=true;
			}
		}
		if((i==0 && bfs(w,h,0,0,gy,gx)) || (i>0 && flag && bfs(w,h,open[i].first,open[i].second,gy,gx))) {
			cout<<i<<endl;
			return 0;
		}
		flag=false;
	}
	cout<<-1<<endl;
	return 0;
}

			