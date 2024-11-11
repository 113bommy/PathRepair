#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll x,n,d,y;
    cin>>n>>d;
    ll cnt=0;
    while(n--){
        cin>>x>>y;
        if(x*x+y*y<=D*D) cnt++;
    }
    cout<<cnt;
}