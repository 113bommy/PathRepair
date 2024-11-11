#include<bits/stdc++.h>
using namespace std;
#define N 10001
char s[N][N];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#')s[i][j]='#';
			if(s[i][j]=='.'){
				s[i][j]='0';
				for(int p=i-1;p<=i+1;p++){
					for(int q=j-1;q<=j+1;q++){
						if(s[p][q]=='#')s[i][j]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<char(s[i][j]);
		}
		cout<<endl;
	}
	return 0;
}}