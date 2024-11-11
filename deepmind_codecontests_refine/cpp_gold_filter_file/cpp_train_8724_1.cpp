#include<bits/stdc++.h>
using namespace std;
int a[31];
int main(){
	int n,m,i,j,k,num,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>num;
			a[num]++;
		} 
	}
	for(i=1;i<=m;i++){
		if(a[i]==n) ans++; 
	}
	cout<<ans;
	return 0;
}