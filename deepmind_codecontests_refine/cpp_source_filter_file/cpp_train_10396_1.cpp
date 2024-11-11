#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<int> a(n, 0), b(n, 0);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 1;
    
    set<int> s;
    for(int i = 0; i < n; ++i)
        s.insert(b[i]);
    
    auto many = [&] (int x, int y) {
        auto lf = lower_bound(a.begin(), a.end(), x);
        if(lf == a.end())
            return 0;
        auto rt = upper_bound(a.begin(), a.end(), y);
        rt--;
        return (rt - lf + 1);
    };

    for(int i = 0; i < n; ++i) {
        int x = *(s.begin());
        s.erase(s.begin());
        ans = 1LL * ans * (many(min(x, a[i]), max(x, a[i]))) % MOD;
    }

    cout << ans << "\n";
}