#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
#define rep(i, n) for(ll (i) = 0; (i) < (n) ; (i)++ )

int main(void){
    ll n; string s; multiset<pl> rs, ls;
    cin >> n;

    rep(i, n){
        cin >> s;
        ll cur = 0, bottom = 0;
        rep(j, s.length()){
            cur += (s[j] == '(') * 2 - 1;
            bottom = min(bottom, cur);
        }
        if (cur >= 0) ls.insert({bottom, cur});
        else rs.insert({bottom - cur, -cur});
    }

    ll lv = 0, rv = 0;
    auto it = ls.rbegin();
    auto update = [&](ll& val) -> bool{
        pl p = *(it++);
        if (p.first + val >= 0) {val += p.second; return true;}
        else return false;
    };

    while(it != ls.rend()) if (!update(lv)) {cout << "No" << endl; return 0;}
    it = rs.rbegin();
    while(it != rs.rend()) if (!update(rv)) {cout << "No" << endl; return 0;}
    if (lv == rv) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}