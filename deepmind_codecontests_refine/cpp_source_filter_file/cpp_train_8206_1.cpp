#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005
int n;
ll a[maxn],x,y,ans=10000000000000000LL;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=0;i<n-1;i++){
		x+=a[i];
		ans=min(ans,abs(2*x-sum));
	}
	cout<<ans<<endl;
	return 0;
}
