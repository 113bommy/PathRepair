#include <bits/stdc++.h>
#define MAXN (100010)
using namespace std;
int p[MAXN], y[MAXN];
vector<int> vec[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i] >> y[i];
        vec[p[i]].push_back(y[i]);
    }
    for (int j = 1; j <= n; ++j) {
        sort(vec[j].begin(), vec[j].end());
    }
    for (int k = 1; k <= m; ++k) {
        printf("%06d%06d\n", p[k], lower_bound(vec[p[k]].begin(), vec[p[k]].end(), y[k]) - vec[p[k]].begin() + 1);
    }
}
