#include<bits/stdc++.h>

using namespace std;

int a[20][2], n, f[262144][19][2];
int F(int i,int j,int ok)
{
    if(f[i][j][ok]!=-1) return f[i][j][ok];
    if(i==(1<<n)-1) return 0;

    int res = 1e9, sl = 0, t = 0;
    for(int id = 1; id <= n; id++)
        if(i >> (id-1) &1) sl++;
    for(int id = 1; id <= n; id++)
    {
        if(i >> (id-1) & 1 ^ 1)
        {
            int nok = abs(sl-id+1)%2;
            if(a[id][nok] >=a [j][ok]) res = min(res, F(i|(1<<(id-1)), id, nok) + id - t - 1);
        }
        else t++;
    }
    f[i][j][ok] = res;
    return res;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];

    memset(f, -1, sizeof(f));
    int ans = F(0,0,0);
    if(ans == 1e9) ans = -1;
    cout << ans;
}
