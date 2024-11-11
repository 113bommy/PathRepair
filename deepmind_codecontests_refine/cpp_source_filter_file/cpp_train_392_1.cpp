#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) 
	    cin<<a[i],b[i]=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(b[i]==a[1]) cout<<a[2]<<endl;
		else cout<<a[1]<<endl;
	}
	return 0;
}