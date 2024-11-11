#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to;
    int cost;
    edge(int a, int b) : to(a), cost(b) {}
};


vector<int> dist;
vector<vector<edge>> e;
int N;

int dfs1(int p, int par = -1)
{
    int& res = dist[p];
    for (auto x : e[p]) {
        if (x.to == par) continue;
        res = max(res, x.cost + dfs1(x.to, p));
    }
    return res;
}

int dfs2(int p, int d_par = 0, int par = -1)
{
    vector<pair<int, int>> d;
    d.emplace_back(0, -1);
    for (auto x : e[p]) {
        if (x.to == par) d.emplace_back(d_par + x.cost, x.to);
        else d.emplace_back(dist[x.to] + x.cost, x.to);
    }
    sort(d.rbigin(), d.rend());
    int res = d[0].first + d[1].first;
    for (auto x : e[p]) {
        if (x.to == par) continue;
        res = max(res, dfs2(x.to, d[x.to == d[0].second], p));
    }
    return res;
}

int main()
{
    cin >> N;
    dist.resize(N, 0);
    e.resize(N);
    for (int i = 0; i < N-1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        e[s].emplace_back(t, w);
        e[t].emplace_back(s, w);
    }
    dfs1(N / 2);
    cout << dfs2(N / 2) << endl;
}
