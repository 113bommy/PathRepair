#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;

void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int main() {
	// your code goes here
	inr n, k;
	int64_t ans = 1;
	cin >> n >> k;
	vector<int64_t> a, b, A;
	for(int i = 0; i < n; ++i){
		int64_t l;
		cin >> l;
		A.push_back(abs(l));
		if(l < 0)b.push_back(l);
		else if(l > 0) a.push_back(abs(l));
	}
	
	int szn = b.size(), szp = a.size();
	
	if((szp + szn/2*2 >= k) && (k%2 == 0 || szp > 0)){
		sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
		if(k%2)ans = a[0];
		vector<int64_t> V;
		for(int i=k%2; i+1<szp; i+=2) V.push_back(a[i]*a[i+1]);
        for(int i=0; i+1<szn; i+=2) V.push_back(b[i]*b[i+1]);
        sort(V.rbegin(), V.rend());
        for(int i=0; i<k/2; i++) mul(ans, V[i] % MOD);
	}
	else{
		sort(A.begin(), A.end());
        for(int i=0; i<k; i++) mul(ans, A[i]);
        ans = (MOD-ans) % MOD;
	}
	
	cout << ans << endl;
	return 0;
}