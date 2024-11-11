#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans=1000000000000000000;
long long x,y;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		y+=a[i];
	}
	for(int i=0;i<n-1;i++){
		x+=a[i];
		y-=a[i];
		ans=min(ans,abs(y-x));
	}
	cout<<ans;
	return 0;
}