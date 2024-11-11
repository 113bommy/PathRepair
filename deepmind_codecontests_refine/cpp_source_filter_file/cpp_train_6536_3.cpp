//todo: compare with tle
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll arr[2000050];
ll g(int x,int y)
ll f(int x,int y)
ll cal(ll a,int b)
int main(){  
	int r1, r2, c1, c2;  
	arr[0]=1;
	for (int i=1;i<2000010;i++) arr[i]=(arr[i-1]*(ll)i)%MOD;
	cin>>r1>>c1>>r2>>c2;
	ll ans=g(r2,c2)-g(r1-1,c2)-g(r2,c1-1)+g(r1-1,c1-1);
	ans%=MOD;
	if (ans<0) ans+=MOD;
	cout<<ans;
	return 0;
}

ll g(int x,int y) {
	ll sum=0;
	for (int i=1;i<=x+1;i++) 
		(sum+=f(i,y))%=MOD;
	return sum;
}

ll f(int x,int y) {
	return arr[x+y]*cal(arr[x],MOD-2)%MOD*cal(arr[y],MOD-2)%MOD;
}

ll cal(ll a,int b) {
	if (b==0) return 1;
	if (b%2==1) return a*cal(a*a%MOD,b/2)%MOD;
	else return cal(a*a%MOD,b/2); 
}
