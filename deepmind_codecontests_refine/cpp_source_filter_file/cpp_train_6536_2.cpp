#include <iostream>
using namespace std;
#define ll long long

const int mod = 1e9+7, maxn = 2000010;
int r1, c1, r2, c2;

ll pre[maxn];
ll inv[maxn];
ll prei[maxn];
void build(int n){
    pre[1] = pre[0] = 1, inv[1] = inv[0] = 1, prei[1] = prei[0] = 1;
    for(int i = 2 ; i <= n ; i++){
        pre[i] = pre[i-1] * i % mod;
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
        prei[i] = prei[i-1] * inv[i] % mod;
    }
}
ll C(int n, int k){
   return pre[n] * prei[k] % mod * prei[n-k] % mod;
}

ll solve(int x, int y){
    for (x == 0 || y == 0) return 0;
    ll ret = 0;
    for (int i = 1; i <= y; i++){
        ret += c(x+i+1, i+1);
    }
    ret -= y;
    return ret % mod;
}

int main(){
    build(2000005);
    cin >> r1 >> c1 >> r2 >> c2;
    cout << (solve(r2, c2)-solve(r1-1, c2)-solve(r2, c1-1)+solve(r1-1, c1-1)+mod*2)%mod << "\n";
}
