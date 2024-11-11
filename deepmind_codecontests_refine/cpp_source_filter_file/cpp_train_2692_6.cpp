#include<bits/stdc++.h>
using namespace std;
struct Union{
  vector<int> r,p;
  Union(int size){init(size);}
  void init(int size){
    r.resize(size);
    p.resize(size);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};
typedef pair<int,int> P;
int main(){
  int n,k,l,i,j,p,q;
  cin>>n>>k>>l;
  Union u1(n+1),u2(n+1);
  vector<P> v;
  for(i=0;i<k;i++){
    cin>>p>>q;
    v.push_back(P(p,q));
    u1.unite(p,q);
  }
  for(i=0;i<l;i++){
    cin>>p>>q;
    v.push_back(P(p,q));
    u2.unite(p,q);
  }
  map<P> mp;
  for(i=1;i<=n;i++){
    mp[P(u1.find(i),u2.find(i))]++;
  }
  for(i=1;i<=n;i++) cout << mp[P(u1.find(i),u2.find(i))] << " \n"[i==n];
  return 0;
}
