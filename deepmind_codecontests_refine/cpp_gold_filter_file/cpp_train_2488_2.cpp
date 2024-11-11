#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)(n);i++)
#define FORR(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ZERO(a) memset(a,0,sizeof(a))
#define len(a) sizeof(a)
#define ll long long
#define pii pair<int,int>
#define INF 1<<29
#define MAX 3333
using namespace std;

int x[MAX],y[MAX];

void solve(){
 int n;
 for(;;){
  cin>>n;
  if(!n) break;
  FOR(i,n) cin>>x[i]>>y[i];
  set<pii> st;
  FOR(i,n) st.insert(mp(x[i],y[i]));
  int ma=0;
  FOR(i,n){
   FORR(j,i+1,n){
    pii v(x[j]-x[i],y[j]-y[i]),p(x[i]+v.second,y[i]-v.first),q(x[j]+v.second,y[j]-v.first),r(x[i]-v.second,y[i]+v.first),s(x[j]-v.second,y[j]+v.first);
    if((st.find(p)!=st.end()&&st.find(q)!=st.end())||(st.find(r)!=st.end()&&st.find(s)!=st.end())){
     ma=max(ma,v.first*v.first+v.second*v.second);
    }
   }
  }
  cout<<ma<<endl;
 } 
}

int main(){
 solve();
 return 0;
}