#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue <ll> P;
priority_queue <ll,vector <ll>,greater <ll> > Q;

int main() {
    int n;
    ll A=0,B=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
	cin>>l>>r;
	B+=r-l;
	P.push(r-A),Q.push(r-B);
	while(P.top()+A>Q.top()+B) {
	    ll x=P.top()+A,y=Q.top()+B;
	    P.pop(),Q.pop(),ans+=x-y;
	    P.push(y-A),Q.push(x-B);
	}
	A-=r-l;
    }
    cout<<ans;
    return 0;
}