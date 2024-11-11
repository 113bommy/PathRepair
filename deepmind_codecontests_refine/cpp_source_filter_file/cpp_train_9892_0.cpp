#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,pos;
vector<int> pre,in,post;
void rec(int l,int r){
  if(l>=r) return;
  int root=pre[pos++];
  int m=distance(in.begin(),find(int.begin(),in.end(),root));
  rec(l,m);
  rec(m+1,r);
  post.push_back(root);
}
void solve(){
  pos=0;
  rec(0,pre.size());
  REP(i,n){
    if(i) printf(" ");
    printf("%d",post[i]);
  }
  printf("\n");
}
int main(){
  int k;
  scanf("%d",&n);
  REP(i,n) {scanf("%d",&k);pre.pusf_back(k);}
  REP(i,n) {scanf("%d",&k);in.pusf_back(k);}
  solve();
  return 0;
}