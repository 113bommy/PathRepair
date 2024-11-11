#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
// #include <bitset>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <ctime>
// #include <iomanip>
// #include <cstdlib>
using namespace std;

/// ================================ Define Part ================================
#define FOR(i, l, r)  for (int(i) = int(l); int(i) <= int(r); i += 1)
#define FORD(i, r, l) for (int(i) = int(r); int(i) >= int(l); i -= 1)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eol '\n'
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itr iterator
#define rtr reverse_iterator

#define hashmap unordered_map
#define hashset unordered_set
enum enum_t {White, Black, Gray};
typedef long long      ll;      
typedef unsigned int   uint;    typedef unsigned long long ull;
typedef double         db;      typedef long double   ldb;
typedef pair<int, int> pi;      typedef map<int, int> mi;       typedef set<int> si;            typedef set<pi>  spi;
typedef pair<ll, ll>   pll;     typedef map<ll, ll>   mll;      typedef set<ll>  sll;           typedef set<pll> spll;

#define V1(x) vector<x>
#define V2(x) vector<V1(x)>
#define V3(x) vector<V2(x)>
#define V4(x) vector<V3(x)>
typedef V1(enum_t)   ve;        typedef V2(enum_t)   v2_e;      typedef V3(enum_t)   v3_e;      typedef V4(enum_t)   v4_e;
typedef V1(string)   vs;        typedef V2(string)   v2_s;      typedef V3(string)   v3_s;      typedef V4(string)   v4_s;
typedef V1(bool)     vb;        typedef V2(bool)     v2_b;      typedef V3(bool)     v3_b;      typedef V4(bool)     v4_b;
typedef V1(char)     vc;        typedef V2(char)     v2_c;      typedef V3(char)     v3_c;      typedef V4(char)     v4_c;
typedef V1(int)      vi;        typedef V2(int)      v2_i;      typedef V3(int)      v3_i;      typedef V4(int)      v4_i;
typedef V1(ll)       vll;       typedef V2(ll)       v2_ll;     typedef V3(ll)       v3_ll;     typedef V4(ll)       v4_ll;
typedef V1(pi)       vpi;       typedef V2(pi)       v2_pi;     typedef V3(pi)       v3_pi;     typedef V4(pi)       v4_pi;
typedef V1(pll)      vpll;      typedef V2(pll)      v2_pll;    typedef V3(pll)      v3_pll;    typedef V4(pll)      v4_pll;
/// ================================ Independent  Functions ================================
template<typename T>inline void maximize(T &a, T b) { a = (a > b) ? a : b; }
template<typename T>inline void minimize(T &a, T b) { a = (a < b) ? a : b; }
template<typename T>inline bool ifmax(T &a, T b) { return (a < b) ? a = b, true : false; }
template<typename T>inline bool ifmin(T &a, T b) { return (a > b) ? a = b, true : false; }
template<typename T>inline tuple<T,T,T> extgcd(T a,T b) { if(a==0)return make_tuple(b,0,1);T g,x,y;tie(g,x,y)=extgcd(b%a,a);return make_tuple(g,y-(b/a)*x,x); }
template<typename T>inline         T       gcd(T a,T b) { while (b != 0) swap(b, a %= b); return a; }
template<typename T>inline         T       lcm(T a,T b) { return a / gcd(a, b) * b; }
template<typename T>inline bool bitGet   (T  x, int bit)         { return T(1) & (x >> bit); }
template<typename T>inline void bitSet   (T &x, int bit)         { x |=  (T(1) << bit); }
template<typename T>inline void bitReset (T &x, int bit)         { x &= ~(T(1) << bit); }
template<typename T>inline void bitFlip  (T &x, int bit)         { x ^=  (T(1) << bit); }
template<typename T>inline void bitMake  (T &x, int bit, bool v) { x ^=  (T(1) << bit) & (-v ^ x); }
template<typename T>inline void writeUnsign(T n) { if (n > 9) writeUnsign(n / 10);  putchar(n % 10 + '0'); }
template<typename T>inline void writeSigned(T x) { if (x < 0) putchar('-'), x = -x; writeUnsign(x);        }
template<typename T>inline void getString (T& s) {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');s.clear();s.pb(c);while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s.pb(c);}
template<typename T>inline void getUnsign (T& n) {char c;while(c=getchar(),c<'0'||c>'9');n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';}
template<typename T>inline void getSigned (T& n) {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign(c=='-');if(sign)c=getchar();n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';if(sign)n=-n;}
template<typename T,typename...V> inline void getUnsign(T &t, V&...v) { getUnsign(t); getUnsign(v...); }
template<typename T,typename...V> inline void getSigned(T &t, V&...v) { getSigned(t); getSigned(v...); }
inline int    readInt()    { int x;    return getSigned(x), x; }    inline uint readUINT()   { uint x; return getUnsign(x), x; }
inline ll     readLong()   { ll  x;    return getSigned(x), x; }    inline ull  readULL()    { ull  x; return getUnsign(x), x; }
inline string readString() { string s; return getString(s), s; }    inline vc   readVecStr() { vc   s; return getString(s), s; } 
inline void file_inp(const string FILE = "Test") { freopen((FILE + ".INP").c_str(), "r", stdin);  }
inline void file_out(const string FILE = "Test") { freopen((FILE + ".OUT").c_str(), "w", stdout); }
inline void file    (const string FILE = "Test") { file_inp(FILE); file_out(FILE); }
/// ================================ Dependent  Functions ================================
// const db oo = 0.1 / 0; /// inf
// const db PI = acos(-1);
const ll LINF = (1LL << 60); /// 1e18
const int INF = (1 << 30); /// 1e9
const int LIM = (1 << 24); /// 1e7
const int MOD = 1e9 + 7;
const int BASE = 1e4;
const int DIGIT = 4;
const int MAXVAL = 1e6 + 500;

/// ================================ Main part ================================

int n, k;
vector<int> a;
bool solve(int x)
{
    int res = 1;
    for (int i = 0, p = 0; i < n; ++i, ++x)
    {
        while (p + 1 < n && a[p + 1] <= x) p++;
        res = (1LL * res * (p - i + 1)) % k;
        if (res == 0) return false;
    }

    return true;
}

int main()
{
    getUnsign(n, k);

    a.resize(n);
    for (int i = 0; i < n; ++i)
        getUnsign(a[i]);

    sort(all(a));

    vector<int> res;
    int mn = *min_element(all(a));
    int mx = *max_element(all(a));
    for (int x = mn; x <= mx; ++x)
        if (solve(x))
            res.push_back(x);

    cout << res.size() << eol;
    for (int x : res)
        cout << x << ' ';
    return 0;
}