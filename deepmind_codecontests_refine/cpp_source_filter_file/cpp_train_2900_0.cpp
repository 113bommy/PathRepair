#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int i o,t,j,l,s,z,q;
    cin>>i>>o>>t>>j>>l>>s>>z;
    if (i>0&&j>0&&l>0)q=2*((i-1)/2+(j-1)/2+(l-1)/2)+o+3;
    else q=0;
	cout<<max(2*(i/2+j/2+l/2)+o,q);
}