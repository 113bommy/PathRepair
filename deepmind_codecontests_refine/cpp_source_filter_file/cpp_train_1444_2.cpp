#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

ll n, s;

ll ds(ll n, int b){
	ll s = 0;
	while(n){
		s += n % b;
		n /= b;
	}
	return s;
}

int main(){
	cin >> n >> s;
	ll d = n - s;
	if(d <= 0){
		cout << (d == 0 ? n + 1 : -1) << endl;
		return 0;
	}
	int i;
	for(i = 2; ll(i) * i <= n; ++i){
		if(ds(n, i) == s){
			cout << i << endl;
			return 0;
		}
	}
	for(--i; i > 0; --i){
		if(d % i == 0 && s >= i && d / i >= max(i, s - i)){
			cout << d / i + 1 << endl;
			return 0;	
		}
	}
	cout << -1 << endl;
	return 0;
}