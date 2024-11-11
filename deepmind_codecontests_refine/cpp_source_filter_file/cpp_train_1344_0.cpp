#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
double ijk[30][31][31];
int v[30][31][31];
int g[30][30];
int lim[30][30];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		int S,T;
		scanf("%d%d",&S,&T);
		S--;T--;
		for(int i=0;i<a;i++)
			for(int j=0;j<a;j++)
				g[i][j]=-1;
		for(int i=0;i<b;i++){
			int p,q,r,s;
			scanf("%d%d%d%d",&p,&q,&r,&s);
			p--;q--;
			g[p][q]=g[q][p]=r;
			lim[p][q]=lim[q][p]=s;
		}
		for(int i=0;i<a;i++)
			for(int j=0;j<31;j++)
			for(int k=0;k<31;k++){ijk[i][j][k]=99999999;v[i][j][k]=0;}
		priority_queue<pair<double,pair<pair<int,int>,int> > >Q;
		Q.push(make_pair(0,make_pair(make_pair(S,30),1)));
		ijk[S][30][1]=0;
		while(Q.size()){
			double cost=-Q.top().first;
			int at=Q.top().second.first.first;
			int prev=Q.top().xsecond.first.second;
			int ver=Q.top().second.second;
			Q.pop();
			if(~prev&&v[at][prev][ver])continue;
			if(~prev)v[at][prev][ver]=1;
			for(int i=0;i<a;i++){
				if(ver&&~g[at][i]&&lim[at][i]>=ver&&prev!=i){
					if(ijk[i][at][ver-1]>cost+(double)g[at][i]/ver){
						ijk[i][at][ver-1]=cost+(double)g[at][i]/ver;
						Q.push(make_pair(-ijk[i][at][ver-1],make_pair(make_pair(i,at),ver-1)));
					}
					if(ijk[i][at][ver]>cost+(double)g[at][i]/ver){
						ijk[i][at][ver]=cost+(double)g[at][i]/ver;
						Q.push(make_pair(-ijk[i][at][ver],make_pair(make_pair(i,at),ver)));
					}
					if(ver<30&&ijk[i][at][ver+1]>cost+(double)g[at][i]/ver){
						ijk[i][at][ver+1]=cost+(double)g[at][i]/ver;
						Q.push(make_pair(-ijk[i][at][ver+1],make_pair(make_pair(i,at),ver+1)));
					}
				}
			}
		}
		double ret=99999999;
		for(int i=0;i<a;i++)ret=min(ret,ijk[T][i][0]);
		if(ret>9999999)printf("unreachable\n");
		else printf("%f\n",ret);
	}
}