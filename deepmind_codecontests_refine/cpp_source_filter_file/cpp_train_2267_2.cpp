#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
bool f[105];
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[a[i]]=true;
	}
	for(int i=0;i<=n;i++){
		if(!f[x-i]){
			cout<<x-i<<endl;
			return 0;
		}else{
			if(!flag[x+i]){
				cout<<x+i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
