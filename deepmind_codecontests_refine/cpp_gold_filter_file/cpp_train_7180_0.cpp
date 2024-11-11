#include<iostream>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
 
int uf[100100], r[100100];
 
void init(int n){
  rep(i,n)uf[i] = i, r[i] = 0;
}
 
int find(int a){
  if(uf[a] == a)return a;
  return uf[a] = find(uf[a]);
}
 
void unite(int a,int b){
  a = find(a); b = find(b);
  if(a==b)return;
  if(r[a] < r[b])uf[a] = b;
  else{
    uf[b] = a;
    if(r[a] == r[b])r[b]++;
  }
}
 
ll pow(ll a, ll n){
  ll res = 1;
  while(n){
    if(n&1)(res *= a) %= mod;
    (a *= a) %= mod; n>>=1;
  }
  return res;
}
 
int n,m,a,b;
 
int main(){
  cin.tie(0);
  std::ios::sync_with_stdio(false);
 
  while(cin >> n >> m, n){
    init(n);
 
    rep(i,m){
      cin >> a >> b; a--; b--;
      unite(a,b);
    }
 
    map<int,int> g;
    rep(i,n)g[find(i)]++;
     
    ll ans = pow(2,g.size());
    if(m>0)ans++;
    cout << ans%mod << endl;
  }
}