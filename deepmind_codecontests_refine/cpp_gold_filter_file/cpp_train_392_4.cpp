#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) 
	    cin>>a[i],b[i]=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(b[i]==a[n]) cout<<a[n-1]<<endl;
		else cout<<a[n]<<endl;
	}
	return 0;
}