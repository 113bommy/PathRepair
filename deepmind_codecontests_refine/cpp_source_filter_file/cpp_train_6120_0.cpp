#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}"; }
const ld EPS = 0.0000000000001;
const int TIMES = 1000;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<ld> x(n), y(n), c(n);
    map<pair<ll, ll>, int> cnt;
    cout << fixed << setprecision(100);
    for (int i = 0; i < n; i++) {
        ll xx, yy, cc; cin >> xx >> yy >> cc;
        x[i] = xx; y[i] = yy; c[i] = cc;
        cnt[make_pair(xx, yy)]++;
    }
    for (auto p: cnt) {
        if (p.second >= k) {
            cout << 0 << '\n';
            return 0;
        }
    }
    auto dist = [&](ld a, ld b, ld c, ld d) -> ld {
        return sqrt((a - c) * (a - c) + (b - d) * (b - d));
    };
    auto check = [&](ld xx, ld yy, ld t) -> bool {
        int res = 0;
        for (int i = 0; i < n; i++) {
            ld d = dist(xx, yy, x[i], y[i]);
            if (d * c[i] <= t + EPS) {
                res++;
            }
        }
        return res >= k;
    };
    ld lo = 0;
    ld hi = 1e6;
    for (int iter = 0; iter < TIMES; iter++) {
        ld mid = (lo + hi) / 2;
        ld t = mid;
        bool ok = false;
        for (int i = 0; i < n && !ok; i++) {
            for (int j = i + 1; j < n && !ok; j++) {
                ld ri = t / c[i];
                ld rj = t / c[j];
                ld d = dist(x[i], y[i], x[j], y[j]);
                ld ri2 = ri * ri;
                ld rj2 = rj * rj;
                ld d2 = d * d;
                ld sq = (2 * (ri2 + rj2) / d2 - (ri2 - rj2) * (ri2 - rj2) / (d2 * d2) - 1);;
                if (sq < 0) continue;
                sq = sqrt(sq);
                ld xx = (x[i] + x[j]) / 2;
                xx += (ri2 - rj2) / (2 * d2) * (x[j] - x[i]);
                ld yy = (y[i] + y[j]) / 2;
                yy += (ri2 - rj2) / (2 * d2) * (y[j] - y[i]);
                ld xa = sq / 2 * (y[j] - y[i]);
                ld ya = sq / 2 * (x[i] - x[j]);
                ok |= check(xx + xa, yy + ya, t);
                ok |= check(xx - xa, yy - ya, t);
            }
        }
        for (int i = 0; i < n; i++) {
            ok |= (x[i], y[i], t);
        }
        if (ok) hi = mid;
        else lo = mid;
    }
    cout << (lo + hi) / 2 << '\n';
    return 0;
}
