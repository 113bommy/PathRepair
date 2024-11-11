#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
const int N=100010;
int n,m,fg,d[N],t[3],S,w;long long ans;vector<pair<int,int> > e[N];
void dfs(int x){
	t[d[x]]++;S++;
	ref(i,0,((int)e[x].size())-1){
		int y=e[x][i].first;w++;
		int D=(3+d[x]+e[x][i].second)%3;
		if(d[y]==-1)d[y]=D,dfs(y);else if(d[y]!=D)fg=1;
	}
}
int main(){
	cin>>n>>m;
	ref(i,1,m){int x,y;cin>>x>>y;
		e[x].push_back(make_pair(y,1));
		e[y].push_back(make_pair(x,-1));
	}
	ref(i,1,n)d[i]=-1;
	ref(i,1,n)if(d[i]<0){
		fg=d[i]=S=w=T[0]=T[1]=T[2]=0,dfs(i);
		if(fg)ans+=1LL*S*S;else
		if(!t[0]||!t[1]||!t[2])ans+=w/2;else
		ans+=1LL*t[0]*t[1]+1LL*t[1]*t[2]+1LL*t[2]*t[0];
	}
	cout<<ans<<endl;
}