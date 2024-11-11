#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)(n);i++)
#define FORR(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define pb(a) push_back(a)
#define mp(x,y) make_pair(x,y)
#define ALL(a) a.begin(),a.end()
#define ZERO(a) memset(a,0,sizeof(a))
#define len(a) sizeof(a)
#define ll long long
#define pii pair<int,int>
#define INF 1<<29
#define MAX 
using namespace std;

void solve(){
 int D,n,m;
 for(;;){
  cin>>D;
  if(!D) break;
  cin>>n;
  cin>>m;
  int ans=0;
  vector<int> d;
  d.pb(0); d.pb(n);
  int dd;
  FOR(i,n-1){
   cin>>dd;
   d.pb(dd);
  }
  int k,ind;
  sort(ALL(d));
  FOR(i,m){
   cin>>k;
   int ind=upper_bound(ALL(d),k)-d.begin();
   int mi=1000000001;
   if(ind<d.size()) mi=min(mi,v[ind]-k);
   ind--;
   if(ind>=0) mi=min(mi,k-v[ind]);
   ans+=mi;
  }
  cout<<ans<<endl;
 }
}

int main(){
 solve();
 return 0;
}