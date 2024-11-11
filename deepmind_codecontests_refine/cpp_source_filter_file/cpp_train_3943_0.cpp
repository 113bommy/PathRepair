#include<bits/stdc++.h>
#define Mod 1000000007
#define Val(x) (((long long)x) % Mod)
#define maxn 200005
using namespace std;
int fac[maxn];
int Pow(int a,int n) {
	int ret = 1;
	int base = a;
	while(n) {
		if(n&1)	ret = Val(ret*base);
		base = Val(base*base);
		n >>= 1;
	}
	return ret;
}
int cal(int n,int m) {
	return Val(Val(fac[n+m]*Pow(fac[n],Mod-2))*Pow(fac[m],Mod-2));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fac[0] = 1;
	for(int i=1;i<maxn;i++)a
		fac[i] = Val(fac[i-1] * i);
		
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	
	int ans = 0;
	for(int j=b+1;j<=m;j++)
		ans = Val(ans + Val(cal(n-a-1,j-1)*cal(a-1,m-j)));
	
	cout << ans << endl;
	return 0;
}
