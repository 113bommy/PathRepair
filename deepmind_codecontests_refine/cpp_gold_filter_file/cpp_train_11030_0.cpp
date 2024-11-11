#include<iostream>I don't know
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
int stoi(string x){stringstream ss;ss<<x;int tmp;ss>>tmp;return tmp;}
string itos(int x){stringstream ss;ss<<x;return ss.str();}
double ta[300][3];
bool used[300],tused[300];

	int n,m;
double ans=0;
double solve(int now){
double ret=0.0;
while(true){
	tused[now]=0;

	int next=0,f=0;
	for(int i=0;i<n;i++){
		if(tused[i]&&!f)next=i,f=1;
	}
	for(int i=0;i<n;i++){
	if(tused[i]){
		for(int j=0;j<3;j++)ret+=(ta[i][j]-ta[now][j])*(ta[i][j]-ta[now][j]);

		}
	}
	now=next;
	bool endf=1;
	for(int i=0;i<n;i++)if(tused[i])endf=0;
	if(endf)break;
}
return ret;
}
void  dfs(int h,int use){
	if(h==n){
	//for(int i=0;i<n;i++)cout<<used[i]<<" ";cout<<endl;
	if(use==m){
	int next=0;
	for(int i=n-1;i>=0;i--)if(used[i])next=i,tused[i]=used[i];
	ans=max(ans,solve(next));
	}
	return ;
	}
	used[h]=1;
	dfs(h+1,use+1);
	used[h]=0;
	dfs(h+1,use);
}
int main(){

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)cin>>ta[i][0]>>ta[i][1]>>ta[i][2];
	dfs(0,0);
	printf("%.10f\n",ans);
	return 0;
}