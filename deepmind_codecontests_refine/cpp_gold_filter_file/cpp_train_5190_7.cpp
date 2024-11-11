#include "bits/stdc++.h"
using namespace std;
typedef long double ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a>b)
        cout<<"GREATER";
    else if(a<b)
        cout<<"LESS";
    else if(a==b)
        cout<<"EQUAL";    
}