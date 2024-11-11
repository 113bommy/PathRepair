#include<math.h>
#include<iostream>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define INF (1<<30)

using namespace std;

int cost[200][200], time[200][200],dist[200];
int x[200][200];
bool vis[200];
int M,N;

void dij(int p, int q, int r){
	int i,j,k,l,m,n,mn;
	rep(i,M)rep(j,M)x[i][j]= ((r==0)?(cost[i][j]):(time[i][j]));
	rep(i,M)vis[i]=false,dist[i]=INF;
	dist[p-1]=0;
	for(;;){
		k=-1,mn=INF;
		rep(i,M)if(!vis[i]&&dist[i]<mn){mn=dist[i],k=i;}
		if(k==-1 || mn>=INF) break;
		if(k==q-1)break;
		vis[k]=true;
		rep(i,M)if(!vis[i])dist[i]=min(dist[i],dist[k]+x[k][i]);
	}
	cout<<dist[q-1]<<endl;
}

int main(){
	int i,j,k,l,m,n;
	
	while(cin>>N>>M){
		if((N|M)==0) break;

		rep(i,M){
			dist[i]=INF; 
		    rep(j,M){
			  if(i==j) {cost[i][j]=time[i][j]=0; continue;}
			  cost[i][j]=time[i][j]=INF;
			}
		}
		rep(i,N){
			int a,b,c,t;
			cin>>a>>b>>c>>t;
			a--; b--;
			cost[a][b]=cost[b][a]=c; time[a][b]=time[b][a]=t;
		}
		cin>>k;
		rep(i,k){
			int p,q,r;
			cin>>p>>q>>r;
			dij(p,q,r);
		}
	}
}