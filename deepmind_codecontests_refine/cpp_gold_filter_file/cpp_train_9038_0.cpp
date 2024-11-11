#include <bits/stdc++.h>
 
#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl
 
using namespace std;
using ll = long long;
 
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}
 
template <typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& e : v) {
        is >> e;
    }
    return is;
}
 
template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}
 
 
constexpr ll MOD = (ll)1e9 + 7LL;
 
template <typename T>
constexpr T INF = 1LL << 62;
 
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll K;
    cin >> N >> K;
    vector<ll> w(N);
    vector<ll> d(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> d[i];
    }
 
    ll inf = 0;
    ll sup = INF<ll>;
    auto check = [=](const ll mid) {
        unsigned long long n = 0;
        for (int i = 0; i < N; i++) {
            n += (mid < w[i]) ? 0LL : (ll)((mid - w[i]) / d[i] + 1);
        }
        return n >= K;
    };
    while (inf < sup - 1) {
        const ll mid = (inf + sup) / 2;
        if (check(mid)) {
            sup = mid;
        } else {
            inf = mid;
        }
    }
    if (check(sup - 1)) {
        cout << sup - 1 << endl;
    } else {
        cout << sup << endl;
    }
    return 0;
}