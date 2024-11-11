class _in{struct my_iterator{int it;const bool rev;explicit constexpr my_iterator(int it_, bool rev=false):it(it_),rev(rev){}constexpr int operator*(){return it;}constexpr bool operator!=(my_iterator& r){return it!=r.it;}void operator++(){rev?--it:++it;}};const my_iterator i,n;public:explicit constexpr _in(int n):i(0),n(n){}explicit constexpr _in(int i,int n):i(i,n<i),n(n){}constexpr const my_iterator& begin(){return i;}constexpr const my_iterator& end(){return n;}};

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 INF = 1e18;

int R, C, N;
const int MAX_V = 200010;
vector<pair<int, i64>> adj[MAX_V];
bool used[MAX_V];
i64 weight[MAX_V];
void dfs(int cur_v, i64& minR, i64& minC) {
    used[cur_v] = true;
    for(const auto& e : adj[cur_v]) {
        int nxt_v; i64 cost
        tie(nxt_v, cost) = e;
        i64 w = cost - weight[cur_v];
        if(used[nxt_v]) {
            if(w != weight[nxt_v])
              minC = minR = -INF;
            continue;
        }
        
        weight[nxt_v] = w;
        if(nxt_v < R)
          minR = min(minR, w);
        else
          minC = min(minC, w);
        dfs(nxt_v, minR, minC);
    }
}

int main() {
    cin >> R >> C >> N;
    for(int _ : _in(N)) {
        int r, c;
        i64 x;
        cin >> r >> c >> x;
        --r;
        --c;
        c += R;
        adj[r].emplace_back(c, x);
        adj[c].emplace_back(r, x);
    }
    for(int i : _in(R)) if(!used[i]) {
        i64 minR = 0LL, minC = INF;
        weight[i] = 0LL;
        dfs(i, minR, minC);
        if(minC + minR < 0LL) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}