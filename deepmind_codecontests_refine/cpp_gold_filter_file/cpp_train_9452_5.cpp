#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2500;

int N, M, P;
vector<pii> adj[MAXN+10];
ll dist[MAXN+10], ans;

int main()
{
    int i, j;

    scanf("%d%d%d", &N, &M, &P);
    for(i=1; i<=M; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); c-=P;
        adj[a].push_back({b, c});
    }

    for(i=1; i<=N; i++) dist[i]=-987654321;
    dist[1]=0;
    for(i=1; i<=N*2; i++)
    {
        for(int now=1; now<=N; now++)
        {
            for(pii nxt : adj[now])
            {
                if(dist[now]+nxt.second>dist[nxt.first])
                {
                    dist[nxt.first]=dist[now]+nxt.second;
                }
            }
        }
        if(i==N-1) ans=dist[N];
    }
    if(ans!=dist[N]) printf("-1");
    else printf("%lld", max(0ll, dist[N]));
}
