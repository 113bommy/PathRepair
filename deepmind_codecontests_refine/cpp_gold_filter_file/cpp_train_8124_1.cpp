#include <bits/stdc++.h>
using namespace std;
/* 
   kD_Tree
   build:O(n log^2(n))
   search:O(n^(1-1/K)+A)
   K:次元数 A:領域に含まれる点の数
*/


class KDT{
public:
  typedef long long ll; /*型に注意!!!!*/
  struct node{
    vector<ll> point;
    int l,r;
    node(){}
    node(vector<ll> point):point(point){l=r=-1;}
  };
  int K;// K:次元数
  vector<vector<ll> > P;// それぞれの要素はK+1個(各次元の値と固有ID)
  vector<node> G;
  int ok = 0;

  KDT(int K=2):K(K),ok(0){};
  
  void add_point(vector<ll> a/*座標*/){ 
    static int id = 0;
    if((int)a.size() < K+1) a.push_back(id++);
    assert((int)a.size() == K+1);
    P.push_back(a);
  }
  
  int build(int depth=0,int l=0,int r=-2){
    if(r == -2) r = (int)P.size()-1,ok = 1;
    if(l>r) return -1;
    int D=depth%K; // D:ソートする基準の次元
    sort(P.begin()+l,P.begin()+r+1,[&](const vector<ll> &A,const vector<ll> &B){return A[D]<B[D];});

    int m=(l+r)/2,res=G.size();
    G.push_back(node(P[m]));
    int vl=build(depth+1,l,m-1);
    int vr=build(depth+1,m+1,r);
    G[res].l=vl; G[res].r=vr;
    return res;
  }

  vector<vector<ll> > points;//searchの座標集合と固有ID
  void search(int x,int depth,const vector<ll> &ld,const vector<ll> &ru){
    if(P.empty()) return;
    bool f=true;
    for(int i=0;i<K;i++)
      if(G[x].point[i]<ld[i]||ru[i]<G[x].point[i]) f=false;
    
    if(f) points.push_back(G[x].point);
    
    int D = depth%K;// D:ソートする基準の次元
    if(G[x].point[D]<=ru[D]&&G[x].r!=-1) search(G[x].r,depth+1,ld,ru);
    if(ld[D]<=G[x].point[D]&&G[x].l!=-1) search(G[x].l,depth+1,ld,ru);
  }

  
  //[0,K)の要素が座標,K番目の要素が固有IDになっている。
  vector<vector<ll> > search(vector<ll> ld/*左下*/,vector<ll> ru/*右上*/){
    assert(ok);
    points.clear();
    search(0,0,ld,ru);
    return points;
  }
};

int main(){
  int n;
  cin>>n;

  KDT kdt;
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    kdt.add_point({x,y});
  }

  kdt.build();
  int q;
  cin>>q;
  while(q--){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    auto point = kdt.search({a,c},{b,d});
    vector<int> ans;
    for(auto &p:point) ans.push_back(p.back());
    sort(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++) printf("%d\n",ans[i]);
    printf("\n");
  }
  
}

