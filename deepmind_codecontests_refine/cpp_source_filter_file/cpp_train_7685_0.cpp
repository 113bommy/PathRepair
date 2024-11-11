#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<vector<Int> > G(n);
  for(Int i=1;i<n;i++){
    Int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  {
    Int A=0;
    for(Int i=0;i<n;i++)
      A+=G[i].size()&1;
    cout<<A/2<<" ";
  }

  auto check=
    [&](Int x)->Int{
      Int ng=0;
      function<Int(Int, Int)> dfs=
        [&](Int v,Int p){
          vector<Int> vs;
          for(Int u:G[v]){
            if(u==p) continue;            
            vs.emplace_back(dfs(u,v)+1);
          }
          
          if(G[v].size()&1)
            vs.emplace_back(0);
          sort(vs.begin(),vs.end());
          
          Int k=vs.size();
          if(p<0){
            assert(~k&1);
            for(Int i=0;i<k/2;i++)
              if(vs[i]+vs[k-(i+1)]>x) return ng=1;
            return 0;
          }
          
          assert(k&1);
          
          auto check2=
            [&](Int y)->Int{
              vector<Int> us;
              for(Int i=0;i<k;i++)
                if(i!=y) us.emplace_back(vs[i]);
              Int l=us.size();
              assert(~l&1);
              for(Int i=0;i<l/2;i++)
                if(us[i]+us[l-(i+1)]>x) return 0;
              return 1;
            };
          
          Int l=-1,r=k;
          while(l+1<r){
            Int m=(l+r)>>1;
            if(check2(m)) r=m;
            else l=m;
          }
          if(r==k) return ng=1;
          return vs[r];
        };
      
      dfs(0,-1);
      return !ng;
    };
    
  Int l=0,r=n;
  while(l+1<r){
    Int m=(l+r)>>1;
    if(check(m)) r=m;
    else l=m;
  }
  cout<<r<<endl;
  return 0;
}
