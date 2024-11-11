#include <bits/stdc++.h>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

void waf(vector<vector<int>> &dist, int n) {
    rep(k, n) rep (i, n) rep (j , n) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

int main(int argc, const char * argv[]) {
    // source code
    long n, m, l;
    cin >> n >> m >> l;
    vector<vector<long>> dist(n);
    rep (i, n) dist[i].assign(n, INT_MAX);
    rep (i, m) {
        long a, b, c;
        cin >> a >> b >> c;
        dist[--a][--b] = c;
        dist[b][a] = c;
    }
    waf(dist, n);
    rep (i, n) rep (j , n) {
        if (dist[i][j] <= l) dist[i][j] = 1;
        else dist[i][j] = INT_MAX;
    }
    waf(dist, n);
    long Q;
    cin >> Q;
    rep (i, Q) {
        long s, q;
        cin >> s >> q;
        if (dist[--s][--q] < INT_MAX) cout << dist[s][q] - 1 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
