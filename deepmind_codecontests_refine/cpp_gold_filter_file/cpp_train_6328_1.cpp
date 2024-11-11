#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5+10;
ll n,ans,d[20][20],k;
int main () {
    cin >> n;
    for(ll i=1;i<=n;++i) {
        for(k=i;k>=10;k/=10);
        d[k][i%10]++;
    }
    for(int i=1;i<=9;++i) {
        for(int j=1;j<=9;++j) {
            ans+=d[i][j]*d[j][i];
        }
    }
    cout << ans;
}