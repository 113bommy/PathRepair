#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
//C:flow_type,D:cost_type,E:edge_class
template<typename C, typename D, class E>
struct MinCostFlow{
    const D INF = numeric_limits<D>::max();
    vector<vector<E>> g;
    int n;
    int s, t;
    vector<int> pv, pe;
    vector<D> h;
    MinCostFlow(vector<vector<E>> _g, int _s, int _t, bool negative):g(_g),n((int)g.size()), s(_s), t(_t),pv(n),pe(n),h(n){
        assert(s != t);
        if(negative){
            vector<D> dist(n, INF);
            dist[s] = 0;
            for(int c = 0; c < n; c++){
                for(int i = 0; i < n; i++){
                    for(auto &e : g[i]){
                        if(e.cap > 0 and dist[i] < INF){
                            dist[e.to] = min(dist[e.to], dist[i] + e.cost);
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                h[i] += dist[i];
            }
        }
    }
    D solve(C f){
        D res = 0;
        while(f > 0){
            vector<D> dist(n, INF);
            using P = pair<D, int>;
            priority_queue<P, vector<P>, greater<P>>pq;
            dist[s] = 0;
            pq.emplace(dist[s], s);
            while(!pq.empty()){
                auto x = pq.top();
                pq.pop();
                int v = x.second;
                if(dist[v] < x.first)continue;
                for(int i = 0; i < (int) g[v].size(); i++){
                    const auto &e = g[v][i];
                    if(e.cap <= 0)continue;
                    D temp = dist[v] + e.cost + h[v] - h[e.to];
                    if(dist[e.to] > temp){
                        dist[e.to] = temp;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }
            if(dist[t] == INF){
                return D(-1);
            }
            for(int i = 0; i < n; i++){
                h[i] += dist[i];
            }
            if(h[t] > 0)return res;
            C d = f;
            for(int v = t; v != s; v = pv[v]){
                d = min(d, g[pv[v]][pe[v]].cap);
            }
            f -= d;
            res += h[t] * d;
            for(int v = t; v != s; v = pv[v]){
                auto &e = g[pv[v]][pe[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return res;
    }
};
template<class C, class D, class E>
MinCostFlow<C, D, E> get_mcf(const vector<vector<E>>& g, int s, int t, bool negative = false){
    return MinCostFlow<C, D, E>(g, s, t, negative);
}
int main(){
    int n, k;
    cin >> n >> k;
   
    struct E{
        int to, rev, cap;
        ll cost;
    };
    
    vector<vector<E>> g(2 * n + 2);
    auto add_edge = [&](int from, int to, int cap, ll dist) {
        g[from].push_back(E{to, int(g[to].size()), cap, dist});
        g[to].push_back(E{from, int(g[from].size())-1, 0, -dist});
    };
    const int s = 2 * n;
    const int t = 2 * n + 1;
    rep(i,n){
        add_edge(s, i, k, 0);
        add_edge(i + n, t, k, 0);
    }
    rep(i,n)rep(j,n){
        ll x;
        cin >> x;
        add_edge(i, j + n, 1, -x);
    }
    auto mcf = get_mcf<int, ll>(g, s, t);
    cout << -mcf.solve(n * k) << "\n";
    vector<string> ans(n, string(n,'.'));
    rep(i,n){
        for(auto &e: mcf.g[i]){
            if(e.cap == 0)ans[i][e.to-n] = 'X';
        }
    }
    rep(i,n){
        cout << ans[i] << "\n";
    }
}
