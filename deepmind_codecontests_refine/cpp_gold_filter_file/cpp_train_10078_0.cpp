#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll count=0,sum=0,mn=INT_MAX;
    while(n--){
        ll x;
        cin>>x;
        sum+=abs(x);
        if(x<0)count++;
        x=abs(x);
        mn=min(mn,x);
    }
    //this is hacked not the actual solution
    if(count%2==1)sum-=2*mn;
    cout<<sum;
}