#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n)repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
typedef pair<int,int> P;
typedef pair<int, P> PP;
#define all(v) v.begin(),v.end()
#define fi first
#define se second
const int inf = 1e9;

int a[1002], sum[2];
P calc(int n){
	int res = *max_element(a, a+n);
	int p = max_element(a, a+n)-a;
	return P(res, p);
}

signed main(){
	int n;
	scanf("%lld", &n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n)sum[i%2] += max((int)0, a[i]);
	
	P t3 = calc(n);
	rep(i,n)if(i%2 == (sum[0]>sum[1]))a[i] = -1;
	int f = (sum[0] <= sum[1]);
	int mx = max(sum[0], sum[1]);
	
	vector<int> ans;
	if(mx > 0){
		int k = 0;a[n] = 1;
		while(a[k]<=0){ans.push_back(1);k++;}
		if(f^(k%2)){ans.push_back(1);k++;}
		repi(i,k+2,n+1){
			if(a[i] > 0)ans.push_back(2);
			else ans.push_back(3);
			if(i == n-1 && a[i]<=0)ans.push_back(2);
			i++;
		}
		int m = ans.size();
		printf("%lld\n%lld\n",mx, m);
		rep(i,m)printf("%lld\n", ans[i]);
	}else{
		printf("%lld\n%lld\n", t3.fi, n-1);
		drep(i,n-1,t3.se+1)printf("%lld\n", i+1);
		rep(i,t3.se)printf("1\n");
	}
	return 0;
}