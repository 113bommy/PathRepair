#include<bits/stdc++.h>
#define MAXN 400005
#define LL long long
using namespace std;

int N;
string s;

vector<int> adj[26];
int pos[MAXN];

//
int fw[MAXN];

int lbt(int x){
	return x & (-x);
} 

int getsum(int x){
	int ans = 0;
	for(;x;x -= lbt(x)){
		ans += fw[x];
	}
	return ans;
}

void change(int x, int dv){
	for(;x<=2*N;x += lbt(x)){
		fw[x] += dv;
	}
}

//

int main(){
	
	cin>>s;
	N = s.length();
	s = "%" + s;
	
	for(int i=1;i<=N;i++){
		adj[s[i]-'a'].push_back(i);
	}
	
	int n1 = 0;
	for(int i=0;i<26;i++){
		if(adj[i].size()%2) ++n1;
		if(adj[i].size()==0) continue;
		
		int l = 0, r = adj[i].size()-1;
		while(l <= r){
			pos[adj[i][l]] = adj[i][r];
			l++;
			r--;
		}
	}

	if(n1 > 1){
		cout<<"-1"<<endl;
		return 0;
	}
	
	for(int i=1;i<=N;i++){
		//cout<<i<<" "<<pos[i]<<endl;
		change(i, +1);
	}
	
	LL ans = 0;
	int p1 = 0;s
	for(int i=1;i<=N;i++){
		if(pos[i]==0) continue;
		if(pos[i]==i){
			change(N+1, +1);
			continue;
		} 
		++p1;
		ans += getsum(N+1) - getsum(pos[i]);
		//cout<<i<<" "<<getsum(N)<<" "<<getsum(pos[i])<<" "<<ans<<endl;
		change(pos[i], -1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
babaabbbaaa
*/