#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to;
    int cost;
    edge(int a, int b) : to(a), cost(b) {}
};

vector<vector<edge>> e;
int N;

pair<int, int> dfs(int p, int par = -1)
{
    pair<int, int> res = make_pair(0, p);
    for (auto x : e[p]) {
        if (x.to == par) continue;
        auto t = dfs(x.to, p);
        t.first += x.cost;
        res = max(res, t);
    }
    return res;
}

int main()
{
    cin >> N;
    e.resize(N);
    for (int i = 0; i < N-1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        e[s].emplace_back(t, w);
        e[t].emplace_back(s, w);
    }
    auto res = dfs(0);
    res = dfs(res.second);
    cout << res.first << endl;
}
