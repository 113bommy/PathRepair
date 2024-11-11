#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = 998244353;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

struct num { ll i; ll v; };

int main() {
  int N; cin >> N; 
  string X; cin >> X; rep(i,N) X += X[i]=='0' ? '1' : '0';
  N *= 2;
  int tn = 1; while(N%(tn*2)==0) tn*= 2;


  vector<num> ya;
  for (int i=1; i*i<=N; i++) {
    if (N%i==0) {
      if (i%tn==0) ya.push_back({i,0});
      if ((N/i)%tn==0) ya.push_back({N/i,0});
    }
  }
  sort(all(ya),[](const num &x, const num &y){return x.i<y.i;});
  // for(auto x: ya) cout << x.i << " "; cout << endl;
  // cout << X << endl;

  for (auto &x: ya) {
    string ts = X.substr(0,x.i/2); rep(i,x.i/2) ts += ts[i]=='0' ? '1' : '0';
    string s; rep(i,N/x.i) s += ts;
    rep(i,x.i/2) {
      x.v *= 2;
      x.v += X[i] - '0';
      x.v %= MOD;
    }
    x.v += s<=X; x.v %= MOD;
    for (auto y: ya) {
      if (x.i<=y.i) break;
      if (x.i%y.i==0) {
        x.v -= y.v; x.v %= MOD;
      }
    }
    x.v = (x.v%MOD+MOD)%MOD;
  }
  // for(auto x: ya) cout << x.i << "->" << x.v << " "; cout << endl;
  ll result = 0;
  for (auto x: ya) { result += x.i*x.v; result %= MOD; }
  cout << result << endl;
  return 0;
}