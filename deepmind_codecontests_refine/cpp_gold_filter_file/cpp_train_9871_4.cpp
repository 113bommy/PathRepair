#include <iostream>
using namespace std;
using ll = long long;

int N;
int h[200010],a[200010];
ll dp[200010];

ll query(int x){
    ll ret = 0;
    for(int i = x;0 <  x; x -= x & -x) ret = max(ret,dp[x]);
    return ret;
}

void update(int x,ll v){
    for(int i = x;x <= N; x += x & -x) dp[x] = max(dp[x],v);
}

int main(){
    cin >> N;
    for(int i=1;i<=N;++i) cin >> h[i];
    for(int i=1;i<=N;++i) cin >> a[i];
    for(int i=1;i<=N;++i){
        ll t = query(h[i]) + a[i];
        update(h[i],t);
    }
    cout << query(N) << endl;
    return 0;
}