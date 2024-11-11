#include<bits/stdc++.h>
#define maxn 100009
#define mk make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> P;
multiset<int>st[maxn];
map<P,int>mp;
map<P,int>::iterator it;
multiset<int>::iterator jt;
int fa[maxn],sz[maxn];
queue<P>q;
vector<int>vec[maxn];
int find(int x){if(fa[x]!=x) fa[x]=find(fa[x]);return fa[x];}
int main(){
  int n,x,y;
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    scanf("%d%d",&x,&y);
    st[x].insert(y),st[y].insert(x);
    mp[mk(x,y)]+=1,mp[mk(y,x)]+=1;
  }
  for(int i=1;i<n;i++){
    scanf("%d%d",&x,&y);
    st[x].insert(y),st[y].insert(x);
    mp[mk(x,y)]+=1,mp[mk(y,x)]+=1;
  }
  for(it=mp.begin();it!=mp.end();it++)
    if(it->se==2) q.push(it->fi);
  for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,vec[i].pb(i);
  for(int T=1;T<n;T++){
  tp:
    if(q.empty()) puts("NO"),exit(0);
    P u=q.front();q.pop();
    mp.erase(u);
    int x=find(u.fi),y=find(u.se);
    if(x==y) goto tp;
    if(sz[x]>sz[y]) swap(x,y);
    for(jt=st[x].begin();jt!=st[x].end();jt++){
      int k=find(*jt);if(k==y) continue;
      st[y].insert(k),st[k].insert(y),mp[mk(y,k)]+=1,mp[mk(k,y)]+=1;
      if(mp[mk(y,k)]==2) q.push(mk(y,k));
      if(mp[mk(k,y)]==2) q.push(mk(k,y));
      st[k].erase(st[k].find(x));
    }
    st[y].erase(x);t
    fa[x]=y,sz[y]+=sz[x];
  }
  puts("YES");
  return 0;
}
