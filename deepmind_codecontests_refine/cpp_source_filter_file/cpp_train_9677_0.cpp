#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

typedef complex<double> Point;

double angle(const Point& v1, const Point& v2) {
    double res = arg(v1 / v2);
    if (res < 0) res += 2*pi;
    return min(2*pi-res, res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll n; cin >> n;
    double R, th; cin >> R >> th; th *= pi / 180;
    vector<Point> v(n);
    REP(i, n) {
        ll x, y; cin >> x >> y;
        v[i] = Point(x, y);
    }
    vector<vector<vector<bool>>> G(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    REP(i, n) REP(j, n) REP(k, n) {
        if (i == j || j == k || k == i) continue;
        // i -> j -> k テ」ツ?ィテ」ツ??」ツ?妥」ツつ凝」ツ??
        Point v1 = v[j] - v[i];
        Point v2 = v[k] - v[j];
        if (angle(v1, v2) <= th+eps) {
            G[i][j][k] = true;
        }
    }
    vector<vector<double>> dist(n, vector<double>(n));
    REP(i, n) REP(j, n) dist[i][j] = abs(v[i]-v[j]);
    ll ans = 0;
    vector<vector<vector<double>>> dp(2, vector<vector<double>>(n, vector<double>(n, linf)));
    dp[0][0][0] = 0;
    REP(t, 1010) {
        dp[t+1&1].assign(n, vector<double>(n, linf));
        REP(prev, n) REP(now, n) {
            double l = dp[t&1][prev][now];
            if (l >= R) continue;
            ans = max(ans, t);
            REP(to, n) {
                if (prev != now && !G[prev][now][to]) continue;
                if (now == to) continue;
                dp[t+1&1][now][to] = min(dp[t+1&1][now][to], l + dist[now][to]);
            }
        }
    }
    cout << ans << endl;
}