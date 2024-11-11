#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

ll A[100001];
vector<int> G[100001];

inline ll dfs(int u, int p) {
    if (G[u].size() == 1) return A[u];
    ll ret = 2*A[u], m = 0;
    for (int v : G[u]) if (v != p) {
        int x = dfs(v, u);
        ret -= x;
        m = max(x, m);
    }
    if (ret < 0 || ret > A[u] || m > A[u]) {
        cout << "NO";
        exit(0);
    }
    return ret;
}

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    for (int u = 1; u <= N; ++u) cin >> A[u];
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }

    if (N == 2) {
        cout << (A[1] == A[2] ? "YES" : "NO");
        return 0;
    }

    int s = 1;
    while (G[s].size() == 1) ++s;
    cout << (dfs(s, 0) ? "NO" : "YES");
    return 0;
}