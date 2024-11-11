#include <bits/stdc++.h>
using namespace std;

   typedef long long ll;

   const double EPS = (1e-7);
   const ll INF =(1e9);
   const double PI = (acos(-1));
   const ll MOD = ll(1e9) + 7;

   #define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
   #define REPR(i, n) for(ll i = n; i > -1; i--)
   #define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
   #define ALL(x) (x).begin(),(x).end()
   #define SORT(x) sort((x).begin(), (x).end())
   #define REVERSE(x) reverse((x).begin(), (x).end())
   #define SZ(x) ((ll)(x).size())
   #define pb push_back
   #define mp make_pair

   //chmax(a, b): a>bならaをbで更新　更新したときにtrueを返す
   //chmin(a, b): a<bならaをbで更新　更新したときにtrueを返す
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
   template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

   #define dump(x) cerr<< #x << "= " << (x) << endl;

   int gcd(int a,int b){return b?gcd(b,a%b):a;};

   int dx[4]={1,0,-1,0};
   int dy[4]={0,1,0,-1};


const ll MAX_N = 40;

ll n, W;
ll w[MAX_N], v[MAX_N];

pair<ll, ll> ps[1 << (MAX_N / 2)]; //(weight, value)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //input
    cin >> n >> W;
    REP(i, n){
        cin >> v[i] >> w[i];
    }

    //前半 n/2個から自由に選ぶ組み合わせを全列挙
    //(w, v)の和をps[i]に保存
    int n2 = n / 2;
    REP(i, 1 << n2){
        ll sw = 0, sv = 0;
        REP(j, n2){
            if ((i >> j) & 1){
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = mp(sw, sv);
    }

    //wの小さい順->vの小さい順、でソートする
    sort(ps, ps + (1 << n2));
    ll m = 1;
    FOR(i, 1, 1 << n2){
        if (ps[m - 1].second < ps[i].second){
            ps[m++] = ps[i];
        }
    }
    //m = psから(w, v)の関係が逆転している要素を覗いたときの要素数

    //後半を全列挙
    ll res = 0;
    REP(i, 1 << (n - n2)){
        ll sw = 0, sv = 0;
        REP(j, n - n2){
            if ((i >> j) & 1){
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        }
        if (sw <= W){
            ll tv = (lower_bound(ps, ps + m, mp(W - sw, INF)) - 1) -> second;
            res = max(res, sv + tv);
        }
    }
    cout << res << endl;


    return 0;
}
