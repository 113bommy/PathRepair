// Author: getharshkumar

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll N = 1e6 + 6, M = 1e9 + 7;
ll a[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<ll>());
    ll ans = p, i, s = a[p - 1], c = 1;
    for (i = p; i < n; i++, c++)
    {
        if (a[i] + m >= a[p - 1] && (a[i] + m) * c - s >= m * max(0LL, (c - n + v)))
            ans++, s += a[i];
        else
            break;
    }
    for (; i < n; i++)
        if (a[i] == a[i - 1])
            ans++;
        else
            break;
    cout << ans;
    return 0;
}