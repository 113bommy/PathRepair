#include<bits/stdc++.h>
using namespace std;
string S[5000],T[5000],V[5000],A,B,C;int a[5000],b[5000],n,m,dist[5000];
vector<string>U;vector<pair<int,int>>x[500];
int dfs(int s,int g){
	for(int i=0;i<5000;i++)dist[i]=1<<30;
	dist[s]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<x[j].size();k++){
				dist[x[j][k].first]=min(dist[x[j][k].first],dist[j]+x[j][k].second);
			}
		}
	}
	return dist[g];
}
int main(){
	while(true){
		cin>>n>>m;for(int i=0;i<500;i++)x[i].clear();
		if(n==0){break;}U.clear();cin>>A>>B>>C;
		for(int i=0;i<m;i++){
			cin>>S[i]>>T[i]>>a[i]>>b[i];
			U.push_back(S[i]);U.push_back(T[i]);
		}
		sort(U.begin(),U.end());V[0]=U[0];int cnt=1,G,H,I;
		for(int i=1;i<U.size();i++){
			if(U[i]!=U[i-1]){V[cnt]=U[i];cnt++;}
		}
		for(int i=0;i<cnt;i++){
			if(A==V[i])G=i;
			if(B==V[i])H=i;
			if(C==V[i])I=i;
		}
		for(int i=0;i<m;i++){
			int s1=0,t1=0;
			for(int j=0;j<cnt;j++){
				if(S[i]==V[j])s1=j;
				if(T[i]==V[j])t1=j;
			}
			x[s1].push_back(make_pair(t1,a[i]/40+b[i]));
			x[t1].push_back(make_pair(s1,a[i]/40+b[i]));
		}
		cout<<dfs(G,H)+dfs(H,I)<<endl;
	}
	return 0;
}