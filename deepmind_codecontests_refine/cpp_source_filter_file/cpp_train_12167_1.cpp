#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
 
template <typename T1, typename T2> bool chkmin(T1 &x, T2 y) { return y < x ? (x = y, true) : false; }
template <typename T1, typename T2> bool chkmax(T1 &x, T2 y) { return y > x ? (x = y, true) : false; }

const int N = 2003, K = 10004;
int n, k;
string s[N];
bitset<K> dq[N];
int pos[

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    dq[n] = 1;
    for (int i = n - 1; i >= 0; --i)
        dq[i] = dq[i + 1] | (dq[i + 1] << (int)s[i].size());

    vector<pii> a;
    for (int i = 0; i < n; ++i)
        if (dq[i + 1][k - (int)s[i].size()])
            a.emplace_back(i, 0);
    for (int p = 0; p < k; ++p)
    {
        if (a.size() > k) a.resize(k);
        char min_ch = 'z';
        for (auto &el : a)
        {
            int i = el.fi;
            int j = el.se;
            chkmin(min_ch, s[i][j]);
        }
        cout << min_ch;
        vector<pii> b;
        int min_pos = n;
        for (auto &el : a)
        {
            int i = el.fi;
            int j = el.se;
            if (s[i][j] == min_ch)
            {
                if (j + 1 == s[i].size())
                    chkmin(min_pos, i + 1);
                else
                    b.emplace_back(i, j + 1);
            }
        }
        for (int i = min_pos; i < n; ++i)
        {
            int rest = k - p - 1 - (int)s[i].size();
            if (rest >= 0 && dq[i + 1][rest])
                b.emplace_back(i, 0);
        }
        swap(a, b);
    }
    
    return 0;
}