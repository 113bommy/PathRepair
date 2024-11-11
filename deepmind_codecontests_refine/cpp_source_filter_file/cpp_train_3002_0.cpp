#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        vector<double> mon;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                mon.push_back(atan2(y[j] - y[i], x[j] - x[i]));
            }
        }
        sort(mon.begin(), mon.end());
        double mx = 0;
        for (int j = 0; j < n-2; j++) {
            mx = max(mx, mon[j+1] - mon[j]);
        }
        mx = max(mx, ang[0] + 2 * acos(-1.0) - mon[n-2]);
        double ans = (mx > acos(-1.0) ? (mx - acos(-1.0)) / (2 * acos(-1.0)) : 0.0);
        cout << ans << endl;
    }
}