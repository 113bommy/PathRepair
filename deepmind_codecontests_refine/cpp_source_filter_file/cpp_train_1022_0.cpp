#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

#define DUMP(x) cout<<#x<<":"<<(x)<<endl
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class T>
istream& operator>>(istream& is, vector<T>& xs){
  for(auto& x: xs)
	is >> x;
  return is;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& xs){
  for(unsigned int i=0;i<xs.size();++i)
	os << (i?" ":"") << xs[i];
  return os;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  LL N, Q;
  cin >> N >> Q;

  VL as(N*2), bs(N*2);
  cin >> as >> bs;

  if(N == 1){
    while(Q--){
    int p, x, y;
    cin >> p >> x >> y;
    --p;
    as[p] = x;
    bs[p] = y;
    cout<<as[0]+as[1]<<endl;      
    }
    return 0;
  }

  int par = 0;
  LL sum = as[0] + as.back();
  multiset<LL> dels;
  FOR(i,1,2*N-1){
    LL mx = max(as[i], bs[i]);
    LL mn = min(as[i], bs[i]);
    sum += mx;
    if(mx == as[i]) par ^= 1;
    dels.insert(mn - mx);
  }

  while(Q--){
    LL p, x, y;
    cin >> p >> x >> y;
    --p;
if(p==0||p==2*N-1){
sum-=as[p]-x;as[p]=x;
cout<<sum-(par?*dels.rbegin()?0ll)<<endl;continue;
}
    LL mx = max(as[p], bs[p]);
    LL mn = min(as[p], bs[p]);
    sum -= mx;
    if(mx == as[p]) par ^= 1;
    auto it = dels.find(mn - mx);
    dels.erase(it);

    as[p] = x;
    bs[p] = y;
    LL mx2 = max(as[p], bs[p]);
    LL mn2 = min(as[p], bs[p]);
    sum += mx2;
    if(mx2 == as[p]) par ^= 1;
    dels.insert(mn2 - mx2);

    LL ans = 0;
    if(par == 0){
      ans = sum;
    }
    else{
      auto it = dels.rbegin();
      assert(it != dels.rend());
      ans = sum + *it;
    }
    cout << ans << endl;
  }

  return 0;
}
