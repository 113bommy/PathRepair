#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int > pii;
typedef pair<int ,pii > pipii;

void solve();

int N,M,H,K;
int S[1010];
int now[1010];

int main()
{
    while(scanf("%d%d%d%d",&N,&M,&H,&K),N + M + H + K)
    {
        for(int i = 1; i < N + 1; i++)
        {
            scanf("%d",&S[i]);
        }
        solve();
    }
    return 0;
}

void solve()
{
    int ans = 0,mem = 0;
    vector<pii> l;
    for(int i = 0; i < M; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        l.push_back(make_pair(b,a));
    }
    sort(l.begin(),l.end());
    for(int i = 1; i < N + 1; i++)
    {
        now[i] = i;
    }
    for(int i = M - 1; i >= 0; i--)
    {
        int memo = S[l[i].second];
        S[l[i].second] = S[l[i].second + 1];
        S[l[i].second + 1] = memo;
    }
    for(int i = 1; i < K + 1; i++)
    {
        ans += S[i];
    }
    for(int i = 0; i < M; i++)
    {
        int Ma = max(now[l[i].second],now[l[i].second + 1]),
            Mi = min(now[l[i].second],now[l[i].second + 1]);
        if(Mi <= K && K < Ma)
        {
            mem = max(mem,S[Mi] - S[Ma]);
        }
        int memo = now[l[i].second];
        now[l[i].second] = now[l[i].second + 1];
        now[l[i].second + 1] = memo;
    }
    printf("%d\n",ans - mem);
    return;
}