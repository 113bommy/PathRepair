#include<bits/stdc++.h>
using namespace std;

vector<int> g[605];
double kakuritu[605];
double kitaiti[605];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, t; cin >> s >> t; --s, --t;
        g[s].push_back(t);
    }
    kitaiti[n - 1] = 0;
    kakuritu[0] = 1;
    for (int i = 0; i < n; i++) {
        for (auto to : g[i]) {
            kakuritu[to] += kakuritu[i] / (double)g[i].size();
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (auto to : g[i]) {
            kitaiti[i] += (kitaiti[to] + 1) / (double)g[i].size();
        }
    }

    double ans = 0;

    for (int i = 0; i < n; i++) {
        for (auto to : g[i]) {
            double ato;
            if (g[i].size() == 1) continue;
            ato = (kitaiti[i] * g[i].size() - (kitaiti[to] + 1)) / (double)(g[i].size() - 1);
            chmax(ans, (kitaiti[i] - ato) * kakuritu[i]);
        }
    }

    cout << fixed << setprecision(10);
    cout << kitaiti[0] - ans << endl;
}