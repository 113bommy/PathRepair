#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define len(x) (int)(x).size()



using namespace std;
//#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int N = (int)3e5 + 100;
ll inf = 1e18;
int t[N];
ll pref[N] , ansPref[N] , ansSuf[N] , answer[N];
vector<pii>que[N];

struct line{
    ll k , b , x;
    ll get(ll _x){return k * _x + b;}
};
ll cross(line a , line b){
    return ceil((a.b - b.b) / ld(b.k - a.k));
}
vector<line>cht;
void add(line nw){
    while(!cht.empty() && cht.back().k == nw.k && cht.back().b < nw.b)
        cht.pop_back();
    if(!cht.empty() && cht.back().k == nw.k)
        return;
    while(!cht.empty() && cross(nw, cht.back()) <= cht.back().x)
        cht.pop_back();
    if(cht.empty())
        nw.x = -inf;
    else
    nw.x = cross(nw , cht.back());
    cht.pb(nw);
}
ll get(ll x){
    int l = 0 , r = len(cht) - 1;
    while(l != r){
        int mid = (l + r) >> 1;
        if(x >= cht[mid].x){
            if(l + 1 == r) l = r;
            else l = mid;
        }else
            r = mid;
    }
    if(x >= cht[r].x) ++r;
    --r;
    assert(x >= cht[r].x);
    if(r + 1 < len(cht))
        assert(x < cht[r + 1].x);
    return cht[r].get(x);
}
void clr(){
    cht.clear();
}
void solve(int l , int r){
    if(l == r){
        for(auto u : que[l]){
            answer[u.se] = max(answer[u.se] , ansPref[l - 1] + ansSuf[l + 1] + max(0ll , 1 - u.fi));
        }
        return;
    }
    int mid = (l + r) >> 1;
    solve(l , mid);
    solve(mid + 1 , r);
    clr();
    /// we wonder to update for [l , mid]
    for(int i = r + 1; i >= mid + 1; --i){
        add({-i , 1ll*i*(i+1)/2+ansSuf[i]-pref[i-1]});
    }
    ll curbest = -inf;
    for(int i = l; i <= mid; ++i){
        curbest = max(curbest , get(i) + 1ll*i*(i-1)/2 + pref[i-1] + ansPref[i-1]);
        for(auto u : que[i]){
            answer[u.se] = max(answer[u.se] , curbest + t[i] - u.fi);
        }
    }
    clr();
    for(int i = l - 1; i <= mid; ++i){
        add({i , 1ll*i*(i-1)/2+ansPref[i]+pref[i]});
    }
    curbest = -inf;
    for(int i = r; i >= mid + 1; --i){
        curbest = max(curbest , get(-i)+1ll*i*(i+1)/2-pref[i] + ansSuf[i+1]);
        for(auto u : que[i]){
            answer[u.se] = max(answer[u.se] , curbest + t[i] - u.fi);
        }
    }
    /// omamamamagat

}

signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;cin >> n;
    for(int i = 1 ; i <= n; ++i){
        cin >> t[i] , pref[i] = pref[i - 1] + t[i];
    }
    int m;cin >> m;
    for(int i = 0 ; i < m; ++i){
        int p , x;cin >> p >> x;
        que[p].pb({x , i});
    }
    add({0 , 0});
    for(int i = 1; i <= n; ++i){
        /// firstly if we have
        ll cur = get(-i)+1ll*i*(i+1)/2-pref[i];
        if(i)
        ansPref[i] = max(ansPref[i-1],cur);
        /// update cht
        add({i , 1ll*i*(i-1)/2+ansPref[i]+pref[i]});
    }
    /// next is mem
    clr();
    /// calculate for suf
    pref[n + 1] = pref[n];
    add({-(n+1),1ll*(n+1)*(n+2)/2+ansSuf[n+1]-pref[n]});
    for(int i = n; i >= 1; --i){
        ll cur = get(i) + 1ll*i*(i-1)/2 + pref[i-1];
        ansSuf[i] = max(ansSuf[i + 1] , cur);
        add({-i , 1ll*i*(i+1)/2+ansSuf[i]-pref[i-1]});
    }
    clr();
    solve(1 , n);
    for(int i = 0 ; i < m; ++i)
        cout << answer[i] << '\n';
    return 0;
}

