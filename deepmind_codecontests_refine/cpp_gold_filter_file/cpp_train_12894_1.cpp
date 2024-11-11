#include <iostream>
using namespace std;
int a[200005],n;
bool b[200005];
bool pd(int x){for(int i=1;i<=n*2-1;i++) b[i]=(a[i]>=x);b[0]=b[1];
	for(int i=n;i<=n+n;i++){if(b[i]==b[i+1])return b[i];if(b[n+n-i]==b[n+n-i-1])return b[n+n-i];}
}
int main(){
cin>>n;
for(int i=1;i<=n*2-1;i++)cin>>a[i];
int l=1,r=n*2,A=0,md;
while(l<=r){md=(l+r)/2;if(pd(md))l=md+1,A=md;else r=md-1;}cout<<A;}