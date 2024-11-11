#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int n, k;
    cin >> n >> k >> s;
    string t = s;
    reverse(be(t));
    s += t;
    string u = s.substr(0, n);
    for(int i=1;i<=n;i++) m = min(m, s.substr(i, n));
    int x = 1;
    while(x < m.length() && m[0] == m[x]) x++;
    int y = x;
    k--;
    if(k > 17) y = N;
    else y <<= k;
    string ans = "";
    while(ans.length() < n && k > 0) y--, ans += m[0];
    ans += m.substr(x, n - ans.length());
    cout << ans << endl;
    return 0;
}
