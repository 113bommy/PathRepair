#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
ll w[110], v[110], wb;
ll knap[110][110][310];
ll INF = 1LL<<40;

int main() {
    int i, j, l;

    scanf("%lld%lld",&n,&k);
    for (i=1;i<=n;i++) scanf("%lld%lld",&w[i],&v[i]);
    wb = w[1];
    for (i=1;i<=n;i++) w[i] -= wb;
    for (i=0;i<=n;i++) for (l=0;l<=3*n;l++) knap[i][0][l] = -INF;
    knap[0][0][0] = 0;
    for (i=0;i<=n;i++) {
        for (j=1;j<=n;j++) {
            for (l=0;l<=3*n;l++) {
                knap[i][j][l] = max(knap[i][j-1][l],((l>=w[j]&&i>=1)?knap[i-1][j-1][l-w[j]]+v[j]:(-INF)));
            }
        }
    }
    ll res = 0;
    for (i=0;i<=n;i++) {
        for (l=0;l<=min(k-wb*i,3*n);l++) {
            res = max(res,knap[i][n][l]);
        }
    }
    printf("%lld\n",res);

    return 0;
}
