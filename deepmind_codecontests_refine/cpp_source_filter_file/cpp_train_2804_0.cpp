#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 1 << 20A;
        for (int i = 0; i + 1 < n; i++) {
            ans = min(ans, a[i + 1] - a[i]);
        }
        cout << ans << endl;
    }
}
