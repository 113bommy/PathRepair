#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i ++)
#define FORS(i, a, b, c) for(int i = a; i < b; i += c)
#define FORN(i, a, b) for(int i = a; i <= b; i ++)
#define FORD(i, a, b) for(int i = a-1; i >= b; i --)
#define FORE(i, b) for(auto &i:b)
#define REP(i, b) FOR(i, 0, b)
#define REPN(i, b) FORN(i, 0, b)
#define SQ(i) (i*i)
#define ALL(a) a.begin(), a.end()
#define ALLA(a,n) a, a+n
#define SORT(a) sort(ALL(a))
#define SORTA(a, n) sort(ALLA(a, n))
#define REV(a) reverse(ALL(a))
#define REVA(a, n) reverse(ALLA(a, n))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define IN(a, b) (a.find(b) != a.end())
#define BACK(a) a.back(); a.RB()
#define QBACK(a) a.top(); a.pop()
#define PRINT(a) FORE(i, a) cout << i << " "; cout << endl

#define PB  push_back
#define RB  pop_back
#define RF  pop_front
#define INS insert
#define F   first
#define S   second
#define UM  unordered_map
#define US  unordered_set
#define PQ  priority_queue

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL)

// typedef unsigned long long ull;
typedef long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<ll,ll> pll;
typedef queue<int> qi;
typedef queue<double> qd;
typedef queue<ll> qll;
typedef US<int> si;
typedef US<double> sd;
typedef US<ll> sll;
typedef vector<vi> mi;
typedef vector<vd> md;
typedef vector<vll> mll;
typedef vector<pi> vpi;
typedef vector<pd> vpd;
typedef vector<pll> vpll;

const int maxn = 510;

int N;
int s[maxn], t[maxn];
ll u[maxn], v[maxn];
ll ans[maxn][maxn];

int go(ll mask){
  mi temp(N, vi(N));
  vi row(N), col(N);
  REP(i, N){
    if(!s[i] && u[i]&mask) REP(j, N) temp[i][j] = 1;
    if(!t[i] && v[i]&mask) REP(j, N) temp[j][i] = 1;
    if(s[i] && !(u[i]&mask)) REP(j, N){
      if(temp[i][j] == 1) return 0;
      temp[i][j] = -1;
    }
    if(t[i] && !(v[i]&mask)) REP(j, N){
      if(temp[j][i] == 1) return 0;
      temp[j][i] = -1;
    }
  }
  REP(i, N) REP(j, N) if(temp[i][j] == 1) row[i] ++, col[j] ++;
  REP(i, N){
    if(s[i] && u[i]&mask && !row[i]){
      int f = 1;
      REP(j, N) if(temp[i][j] == 0 && (t[j] || col[j]+1 < N)){
        temp[i][j] = 1;
        row[i] ++;
        col[j] ++;
        f = 0;
        break;
      }
      if(f) return 0;
    }
    if(t[i] && v[i]&mask && !col[i]){
      int f = 1;
      REP(j, N) if(temp[j][i] == 0 && (s[j] || row[j]+1 < N)){
        temp[j][i] = 1;
        col[i] ++;
        row[j] ++;
        f = 0;
        break;
      }
      if(f) return 0;
    }
  }
  REP(i, N) REP(j, N) ans[i][j] += (temp[i][j]==1?mask:0);
  return 1;
}

int main(){
  IO; cin >> N;
  REP(i, N) cin >> s[i]; REP(i, N) cin >> t[i]; REP(i, N) cin >> u[i]; REP(i, N) cin >> v[i];
  int ok = 1;
  ll m = 1;
  REP(i, 64) ok &= go(m), m*=2;
  REP(i, N){
    ll t1 = ans[i][0], t2 = ans[0][i];
    FOR(j, 1, N){
      if(s[i]) t1 |= ans[i][j]; else t1 &= ans[i][j];
      if(t[i]) t2 |= ans[j][i]; else t2 &= ans[j][i];
    }
    if(t1 != u[i] || t2 != v[i]) ok = 0;
  }
  if(!ok){
    cout << "-1";
    return 0;
  }
  REP(i, N){REP(j, N) cout << ans[i][j] << " "; cout << endl;}
}
