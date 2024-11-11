#pragma GCC optimize("Ofast")
#include<stdio.h>
#include<vector>
#include<utility> 
#include<queue> 
#include<algorithm>
using namespace std;
long long a[1005],b[1005],c[1005],d[1005],e[1005],f[1005],dir[5]={-1,0,1,0,-1};
bool used[3005][3005]={0},up[3005][3005]={0},down[3005][3005]={0},left[3005][3005]={0},right[3005][3005]={0}; 
vector<long long> x,y;
queue<pair<long long,long long>> que;
long long id_x(long long v){
	return lower_bound(x.begin(),x.end(),v)-x.begin();
}
long long id_y(long long v){
	return lower_bound(y.begin(),y.end(),v)-y.begin();
}
int main(){
	x.emplace_back(100000000000000000);
	x.emplace_back(-100000000000000000);
	y.emplace_back(100000000000000000);
	y.emplace_back(-100000000000000000);
	long long i,j,n,m;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		x.emplace_back(a[i]);
		x.emplace_back(b[i]);
		y.emplace_back(c[i]);
	}
	for(i=0;i<m;i++){
		scanf("%lld%lld%lld",&d[i],&e[i],&f[i]);	
		x.emplace_back(d[i]);
		y.emplace_back(e[i]);
		y.emplace_back(f[i]);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	for(i=0;i<n;i++){
		a[i]=id_x(a[i]);
		b[i]=id_x(b[i]);
		c[i]=id_y(c[i]);
		for(j=a[i];j<b[i];j++){
			up[j][c[i]-1]=1;
			down[j][c[i]]=1;
		}
	}
	for(i=0;i<m;i++){
		d[i]=id_x(d[i]);
		e[i]=id_y(e[i]);
		f[i]=id_y(f[i]);
		for(j=e[i];j<f[i];j++){
			right[d[i]-1][j]=1;
			left[d[i]][j]=1;
		}
	}
	que.push({id_x(0)-1,id_y(0)-1});
	used[id_x(0)-1][id_y(0)-1]=1;
	while(que.size()){
		auto z=que.front();
		que.pop();
		for(i=0;i<4;i++){
			if((!i&&left[z.first][z.second])||(i==1&&up[z.first][z.second])||(i==2&&right[z.first][z.second])||(i==3&&down[z.first][z.second]))
				continue;
			long long r=z.first+dir[i],c=z.second+dir[i+1];
			if(r<0||c<0||r>=(int)x.size()-1||c>=(int)y.size()-1||used[r][c])
				continue;
			used[r][c]=1;
			que.push({r,c});
		} 
	}
	for(i=0;i<(int)x.size();i++){
		if(used[i][0]||used[i][y.size()-1]){
			puts("INF");
			return 0;
		}
	}
	for(i=0;i<(int)y.size();i++){
		if(used[0][i]||used[x.size()-1][i]){
			puts("INF");
			return 0;
		}
	}
	long long ans=0;
	for(i=0;i<(int)x.size()-1;i++)
		for(j=0;j<(int)y.size()-1;j++)
			if(used[i][j]){
				ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
	printf("%lld\n",ans);
}
