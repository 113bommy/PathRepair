#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
signed main(){
	int a,b,c,x=0,y=0;
	cin>>a>>b;
	f(i,a){
		cin>>c;
		x+=c;
	}
	f(i,b){
		cin>>d;
		y+=d;
	}
	cout<<x*y<<endl;
	return 0;
}

