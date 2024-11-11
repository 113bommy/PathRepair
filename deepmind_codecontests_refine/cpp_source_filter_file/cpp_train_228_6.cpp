// 巨菜的ACMer-Happier233

#include <bits/stdc++.h>

using namespace std;

//-----
typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define pw(x) (1ll << (x))
#define bt(x, k) (((x) >> k) & 1)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i, l, r) for(int i=(l);i<(r);++i)
#define per(i, l, r) for(int i=(r)-1;i>=(l);--i)
#define mst(t, v, n) memset(t, v, sizeof(decltype(*(t))) * (n))
#define sf(x) scanf("%d", &(x))
#if (not defined(ACM_LOCAL) || defined(ACM_TEST))
#define endl '\n'
#endif

constexpr int N = int(2e5 + 10);
constexpr int MOD = 998244353;

const int INF = 0x3f3f3f3f;

int c[N];
ll ans[26];

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    fill_n(c, n + 1, 0);
    rep(i, 0, m) {
        int x;
        cin >> x;
        c[x - 1]++;
    }
    per(i, 0, n) {
        c[i] += c[i + 1];
    }
    fill_n(ans, 26, 0);
    rep(i, 0, n) {
        ans[s[i] - 'a'] += c[i] + 1;
    }
    rep(i, 0, 26) {
        printf("%d%c", ans[i], " \n"[i == 25]);
    }
}

int main() {
#ifdef ACM_LOCAL
    freopen("./data/std.in", "r", stdin);
//    freopen("./data/std2.out", "w", stdout);
#endif
#if (not defined(ACM_LOCAL) || defined(ACM_TEST))
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif

#ifdef ACM_LOCAL
    clock_t start = clock();
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
#ifdef ACM_LOCAL
    clock_t end = clock();
    cerr << "Run Time: " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}