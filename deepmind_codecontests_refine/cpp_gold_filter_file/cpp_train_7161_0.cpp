#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> v(N);
    for (size_t i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int DP[10000] = {};
    for (size_t i = 0; i < N; i++) {
        int A = v[i].first;
        int B = v[i].second;
        for (int i = T - 1; i >= 0; i--) {
            DP[i + A] = max(DP[i + A], DP[i] + B);
        }
    }
    cout << *max_element(DP, DP + 10000) << endl;
}
