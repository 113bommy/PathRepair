#include<bits/stdc++.h>
using namespace std;
long long Q,H,S,D,N,ans,t;
int main()
{
    cin>>Q>>H>>S>>D>>N;
    t=min(Q*4,min(H*2,S));
    if(t*2<=D)
      cout<<t*N<<endl;
    else cout<<((N%2)*t)+N/2*D<<endl;
    return 0;
}