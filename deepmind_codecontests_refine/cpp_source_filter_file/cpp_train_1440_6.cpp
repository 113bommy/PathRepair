#include<bits/stdc++.h>                          
using namespace std;
int n,x,a[105];
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i],x-=a[i]
	sort(a+1,a+n+1);
	cout<<n+x/a[1];
	return 0;
}