#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

ll dp[(1<<17)];
ll a[17][17], n;

ll score[(1<<17)];
ll calc_group(ll x) {
	ll score = 0LL;
	for(int i=0;i<n;i++) {
		if(x&(1<<i))
			for(int j=0;j<n;j++)
				if(x&(1<<j) && i < j) 
					score += a[i][j]; 
	}
	return score;
}	

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}

	for(ll mask=1LL;mask<(1<<n);mask++) {
		score[mask] = calc_group(mask);
	}

	for(ll mask=1LL;mask<(1<<n);mask++) {
		ll x = mask;
		int b = 0; 
		do {
        	dp[mask] = max(dp[mask], dp[mask^b] + score[b]);
		} while (b=(b-x)&x);
	}
	cout<<dp[(1<<n)-1];
}