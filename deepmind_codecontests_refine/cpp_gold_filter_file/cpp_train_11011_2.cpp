#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n, k; cin >> n >> k;
	vector<Int> a(n);
	for(auto &i:a) cin >> i;
	for(Int i=0; i<k; ++i){
		vector<Int> b(n+1);
		for(Int j=0; j<n; ++j){
			b[max(Int(0), j-a[j])]++;
			b[min(n, j+a[j]+1)]--;
		}
		for(Int j=1; j<n; ++j)
			b[j] += b[j-1];
		bool f = true;
		for(Int j=0; j<n; ++j){
			a[j] = b[j];
			if(a[j] < n) f = false;
		}
		if(f) break;
	}
	for(Int i=0; i<n; ++i)
		cout << a[i] << " \n"[i+1==n];
}