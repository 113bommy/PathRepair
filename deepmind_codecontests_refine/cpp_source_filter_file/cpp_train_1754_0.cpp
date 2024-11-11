#include "bits/stdc++.h"
#define lpa(i,a,b) for(int i=a; i<b; ++i)
#define lp(i,n) lpa(i,0,n)
using namespace std;
int main()
{
	ll n,a,b,c,d,flag=0;
	cin>>n>>a>>b>>c>>d;
	lp(i,n) if(i*c-d*(n-1-i)<=(b-a) && (b-a)<=i*d-(n-1-i)*c) flag=1;
	if(flag==1) cout<<"YES";
	else cout<<"NO";
}