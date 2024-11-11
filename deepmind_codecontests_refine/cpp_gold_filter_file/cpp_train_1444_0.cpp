#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
using namespace std;

ll N,S;

ll f(ll b,ll n){
    if(n<b) return n;
    return f(b,n/b)+n%b;
}

void solve(){
    if(S>N){
        printf("-1\n");return;
    }
    if(N==S){
        printf("%lld\n",N+1);
        return;
    }
    ll i=0;
    for (i = 2;i*i<=N;i++){
        if(S==f(i,N)){
            printf("%lld\n",i);
            return;
        }
    }
    ll b = 100000000001;
    for (int p = sqrt(N);p>0;p--){
            ll b = (N-S)/p + 1;
            if(b>1&&f(b,N)==S){
                cout << b <<endl;
                return;
            }
    }
    if(b<100000000001)printf("%lld\n",b);
    else printf("-1\n");
}

int main() {
    cin >> N;
    cin >> S;
    solve();
    return 0;
}