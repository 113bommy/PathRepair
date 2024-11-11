#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, a[100005];
int main() {
	scanf("%d", &n);
	for( int i = 0; i < n; i++ ) scanf("%d", &a[i]);
	int ans = 1, t = 0;
	for( int i = 0; i < n; i++ ){
		while( t<n && a[t] > (t-i)*2 ) t++;
		if( t<n && a[t]==(t-i)*2 ) t++;
		ans = 1LL*ans*(t-i)%mod;
	}
	printf("%d\n", ans);
	return 0;
}