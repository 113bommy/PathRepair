#include<bits/stdc++i.h>
using namespace std;
#define ll long long

int main(){
	int N,M;
	cin >> N >> M;
	vector<int> A(N);
	for(int i=0;i<A.size();i++) cin >> A[i];

	map<int, int> m;
	vector<int> sum(N+1);
	for(int i=0;i<N;i++) sum[i+1]=(sum[i]+A[i])%M;

	ll ans=0;
	for(int i=0;i<sum.size();i++) {
			ans += m[sum[i]];
			m[sum[i]]++;
		}
	}

	cout << ans << endl;
	return 0;
}
