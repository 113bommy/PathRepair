#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double, int> pdbi;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1000000000 + 7;
const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

struct SuffixArray {
    int n, k;
    string text;
    vector<int> sa;
    vector<int> rank;
    vector<int> lcp;

    SuffixArray (const string &s)
    : text(s), n(s.size()), sa(n + 1), rank(n + 1), lcp(n)
    {}

    bool comp(int i, int j) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        int ri = i + k <= n ? rank[i + k] : -1;
        int rj = j + k <= n ? rank[j + k] : -1;
        return ri < rj;
    }

    void construct_sa() {
        for (int i = 0; i <= n; i++) {
            sa[i] = i;
            rank[i] = i < n ? text[i] : -1;
        }

        for (k = 1; k <= n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](const int& i, const int& j) {return comp(i, j);});

            vector<int> tmp(n + 1);
            tmp[sa[0]] = 0;
            for (int i = 1; i <= n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);
            }

            for (int i = 0; i <= n; i++) {
                rank[i] = tmp[i];
            }
        }
    }

    void construct_lcp () {
        int h = 0;
        lcp[0] = 0;
        for (int i = 0; i < n; i++) {
            int j = sa[rank[i] - 1];
            if (h > 0) h--;
            for (; j + h < n && i + h < n; h++) {
                if (text[j + h] != text[i + h]) break;
            }
            lcp[rank[i] - 1] = h;
        }
    }

    int low_bd(const string &pt) {
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            int val = text.compare(sa[m], pt.length(), pt);
            if (val < 0) l = m;
            else r = m;
        }
        return r;
    }

    int up_bd(const string &pt) {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            int val = text.compare(sa[m], pt.length(), pt);
            if (val <= 0) l = m;
            else r = m;
        }
        return r;
    }

    bool match(const string &pt) {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            int val = text.compare(sa[m], pt.length(), pt);
            if (val < 0) l = m;
            else r = m;
        }
        return text.compare(sa[r], pt.length(), pt) == 0 ? true : false;
    }

    int count(const string &pt) {
        int l_idx = low_bd(pt);
        if (l_idx == sa.size()) return 0;
        if (text.compare(sa[l_idx], pt.length(), pt) != 0) return 0;
        int r_idx = up_bd(pt);
        return r_idx - l_idx;
    }
};

string t;
int q;
string p[10000];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    cin >> q;
    rep(i, q) cin >> p[i];
    SuffixArray suf(t);
    suf.construct_sa();
    rep(i, q) {
        if (suf.match(p[i])) cout << 1 << endl;
        else cout << 0 << endl;
    }
}