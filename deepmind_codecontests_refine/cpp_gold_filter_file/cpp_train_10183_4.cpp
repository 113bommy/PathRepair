#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> P;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<P> sushis(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushis[i].second >> sushis[i].first;
    }
    sort(sushis.begin(), sushis.end(), greater<P>());
    ll ans = 0;
    set<ll> st;
    stack<P> sk;
    for (int i = 0; i < k; ++i) {
        if (st.count(sushis[i].second)) {
            sk.push(sushis[i]);
        }
        st.insert(sushis[i].second);
        ans += sushis[i].first;
    }
    ll curr = ans;
    ans += st.size() * st.size();
    for (int i = k; i < n; ++i) {
        if (sk.empty()) break;
        if (st.count(sushis[i].second)) continue;
        curr -= sk.top().first;
        sk.pop();
        curr += sushis[i].first;
        st.insert(sushis[i].second);
        ans = max(ans, (ll) (curr + st.size() * st.size()));
    }
    cout << ans << endl;
    return 0;
}