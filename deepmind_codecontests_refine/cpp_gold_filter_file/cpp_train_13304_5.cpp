#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	
	ll l,r; cin>>l>>r;
	if(r-l>=2019) cout << 0 << endl;
	else{
		int m{2020};
		for(ll i=l; i<r; i++){
			for(ll j=i+1; j<=r; j++){
				m = min<ll>(m,(i*j)%2019);
			}
		}
		cout << m << endl;
	}
	
}