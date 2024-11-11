#include<bits/stdc++.h>
using namespace std;
long long a[100002];
int main(){
	long long n,x,ans=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[i]+a[i-1]>x){
			ans+=(a[i-1]+a[i])-x;
			if(a[i-1]>x){
				a[i]=0;
				a[i-1]-=a[i-1]-x
			}else{
				a[i]-=((a[i-1]+a[i])-x);
			}
		}
	}
	cout<<ans;
	return 0;
}
