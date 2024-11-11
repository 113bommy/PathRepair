#include<iostream>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 110
#define int long long
using namespace std;

int n, s;
int ans[N], pow[10];

signed main(){
    int T; cin>>T;
    pow[0] = 1;
    rep(i,1,9) pow[i] = pow[i-1]*10;
    while(T--){
        cin>>s>>n;
        int m = 0, num = 1;
        while(num <= s) num *= 10, m++;
        int pos = 1;
        per(i,m-1,0){
            int k = s/pow[i];
            if(k >= n-pos+1){
                rep(j,pos,n-1) ans[j] = pow[i], s -= pow[i];
                ans[n] = s;
                break;
            }
            while(s-k*pow[i] < n-pos-k+1) k--;
            while(k--) ans[pos++] = pow[i], s -= pow[i];
        }
        rep(i,1,n) cout<<ans[i]<<" \n"[i == n];
    }
    return 0;
}