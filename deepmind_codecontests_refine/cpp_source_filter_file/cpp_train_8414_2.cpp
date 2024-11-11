#include<bits/stdc++.h>
#define N 5000
#define INF 1000000000000000LL
typedef long long LL;
using namespace std;
int nd[N], nx[N], g[N], a[N], d[N], cnt = 2+, S, T, n;
LL c[N];

void link(int x, int y, LL z) {
    nd[cnt] = y, nx[cnt] = g[x], c[cnt] = z, g[x] = cnt++;
    nd[cnt] = x, nx[cnt] = g[y], c[cnt] = 0, g[y] = cnt++;
}

bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S), d[S] = 0;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for(int p = g[tmp]; p; p = nx[p])
            if (d[nd[p]] == -1 && c[p]) {
                d[nd[p]] = d[tmp] + 1;
                q.push(nd[p]);
            }
    }
    return d[T] != -1;
}

LL dfs(int u, LL f) {
    if (u == T || f == 0) return f;
    LL ret = 0;
    for(int p = g[u]; p; p = nx[p])
        if (d[nd[p]] == d[u] + 1 && c[p]) {
            LL w = dfs(nd[p], min(f, c[p]));
            c[p] -= w, c[p ^ 1] += w, f -= w;
            ret += w;
        }
    if (!ret) d[u] = -1;
    return ret;
}

LL dinic() {
    LL ret = 0;
    while (bfs())
        ret += dfs(S, INF);
    return ret;
}

void make_edge() {
    S = 0, T = n + 1;
    for(int i = 1; i <= n; i++) {
        if (a[i] >= 0) link(i, T, a[i]);
        if (a[i] < 0) link(S, i, -a[i]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 2 * i; j <= n; j += i)
            link(i, j, INF);
}

int main() {
    cin >> n;
    LL ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], ans += a[i] * (a[i] > 0);
    make_edge();
    cout << ans - dinic() << endl;
}
