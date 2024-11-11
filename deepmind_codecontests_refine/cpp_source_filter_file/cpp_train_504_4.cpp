#include<bits/stdc++.h>
#define ll long long int
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)
using namespace std;
 /*temp*/

int main(){
    int e, p, q;
    while(cin >> n, n != 0) {
        ll m[4001] = {};
        int a[1000] = {};
        REP(i, n){
            cin >> e >> p >> q;
            m[e] += p * q;
            a[i] = e;
        }
        bool f = true;
        REP(i, n){
            if(m[a[i]] >= 1000000){
                cout << a[i] << '\n';
                m[a[i]] = 0;
                f = false;
            }
        }
        if(f) cout << "NA\n";
    }
    return 0;
}