#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

vector<ll> divisor(ll n){
	vector<ll> ret;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			ret.push_back(i);
			if(i*i!=n)ret.push_back(n/i);
		}
	}
	sort(ret.begin(),ret.end());
	return(ret);
}

int main(){
	ll n,k; cin >> n >> k;
	vector<ll> a(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	vector<ll> b(n);
	vector<ll> v=divisor(sum);
	for(int i=v.size()-1;i>=0;i--){
		b=a;
		ll zz=0;
		for(int j=0;j<n;j++){
			b[j]=b[j]%v[i];
			zz+=b[j];
		}
		int zzz=zz/v[i];
		sort(b.begin(),b.end());
		ll mx=0;
		for(int j=n-1;j>=n-zzz;j--){
			mx+=(v[i]-b[j]);
		}
		if(mx<=k){
			cout << v[i] << endl;
			return 0;
		}
	}
}