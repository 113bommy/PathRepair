#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll n,ll x){
    if(!(n%x)) return n*2-x;
    return n/x*x*2+gcd(x,n%x);
} 
int main(){
    ll n,x; cin>>n>>x;
    cout<<gcd(n-x,x)+n<<endl;
    return 0;
}