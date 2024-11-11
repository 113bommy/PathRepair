#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, a[N], pre[N];
ll m, sum[N], ans;
ll check(int x) {
    ll cnt = 0;
    ans = 0;
    for(int i = 0; i < n; i++) {
        cnt += pre[max(0, x-a[i])];
        ans += sum[max(0, x-a[i])] + (ll)a[i]*pre[max(0, x-a[i])];
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pre[a[i]]++;
    }
    for(int i = N-2; i >= 0; i--) {
        sum[i] = sum[i+1] + (ll)i*pre[i];
        pre[i] += pre[i+1];
    }
    int l = 1, r = 200000, res = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid) >= m) {
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    ll cnt = check(res);
    cout << ans-(cnt-m)*res << '\n';
    return 0;
}