#include <bits/stdc++.h>
using namespace std;
#define N 55
int n,m;
string s[N],r[N];

bool che(int i,int j){
	for(int a=0;a<m;a++){
		for(int b=0;b<m;b++){
			if(s[a+i][b+j]!=r[a][b])
				return 0;
		}
	}
	return 1;
}

bool solve(){
	for(int i=0;i<=n-m;i++)
		for(int j=0;j<=n-m;j++)
			if(che(i,j))
				return 1;
	return 0;		 
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
			cin>>s[i];
	for(int i=0;i<m;i++)
			cin>>r[i];
	if(solve())cout<<"Yes\n";
	else cout<<"No\n";
}