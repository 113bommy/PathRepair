#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n; 
    cin >> n;

    ll a,b;
    ll x=1,y=1;

    for(int i=0;i<n;i++){ 
        cin >> a >> b;
        ll k=max((x+a-1)/a,(y+b-1)/b);
        x=a*k;
        y=b*k;
    }

    cout << x + y << endl;
    
    return 0;
}

