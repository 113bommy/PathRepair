#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

int mi[2005];

int main(){
	int n,x; cin >> n >> x;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		mi[i]=a[i];
	}
	ll ans=1e18;
	for(int i=0;i<n;i++){
		ll sum=0;
		for(int j=0;j<n;j++){
			sum+=mi[j];
		}
		ans=min(ans,sum+x*i);
		for(int j=0;j<n;j++){
			mi[j]=min(mi[j],a[(j+n-i-1)%n]);
		}
	}
	cout << ans << endl;
}