#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    REP(j,Q) {
        ll x; cin >> x;
        ll res = 0;
        int right = 0;
        ll sum = 0;
        FOR(left,n) {
            while (right < n && sum + a[right] <= x) {
                sum += a[right];
                ++right;
            }
            res += right - left;
            if (right == left) ++right;
            else sum -= a[left];
        }
        cout << res << endl;
    }
}
