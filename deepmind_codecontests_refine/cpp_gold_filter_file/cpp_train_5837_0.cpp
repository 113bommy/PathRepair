#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query{
  int type;//0=empty, 1=add-sum ,2=set-min
  ll value;
  query(int a=0,ll b=0):type(a),value(b) {}
};



ll INF=(1LL<<60);


struct segtree{
  int SIZE;
  vector<query> s;
  vector<ll> t;// sum-add
  vector<ll> u;// min-set

  segtree(int n=1){
    SIZE=1;
    while(SIZE<n)SIZE*=2;
    s.clear();
    t.clear();
    u.clear();
    s.resize(SIZE*2, query());
    t.resize(SIZE*2, 0);
    u.resize(SIZE*2, 0);
  }
  
  void func(int k,int l,int r,query q){
    if(q.type==1){
      if(s[k].type==0)s[k]=q;
      else s[k].value+=q.value;
      t[k]+=q.value*(r-l);
      u[k]+=q.value;
    }
    if(q.type==2){
      s[k]=q;
      t[k]=q.value*(r-l);
      u[k]=q.value;
    }
  }

  void compute(int k,int l,int r){
    query q=s[k];
    s[k]=query();
    if(q.type==0||r-l==1)return;
    int m=(l+r)/2;
    func(k*2+1,l,m,q);
    func(k*2+2,m,r,q);
  }

  void Update(int a,int b,query x,int k,int l,int r){
    if(b<=l || r<=a)return;
    compute(k,l,r);
    if(a<=l && r<=b){
      func(k,l,r,x);
    }else{
      int m=(l+r)/2;
      Update(a,b,x,k*2+1,l,m);
      Update(a,b,x,k*2+2,m,r);
      t[k]=t[k*2+1]+t[k*2+2];
      u[k]=min(u[k*2+1],u[k*2+2]);
    }
  }

  ll Dfs(int type,int a,int b,int k,int l,int r){
    if(b<=l || r<=a){
      if(type==1)return 0; //add
      if(type==2)return INF; // min
    }
    compute(k,l,r);
    if(a<=l && r<=b){
      if(type==1)return t[k];
      if(type==2)return u[k];
    }else{
      int m=(l+r)/2;
      ll lv=Dfs(type,a,b,k*2+1,l,m);
      ll rv=Dfs(type,a,b,k*2+2,m,r);
      if(type==1)return lv+rv; // add
      if(type==2)return min(lv,rv); // min
    }
  }

  void Add(int a,int b,ll x){
    Update(a,b,query(1,x), 0,0,SIZE);
  }
  void Set(int a,int b,ll x){
    Update(a,b,query(2,x), 0,0,SIZE);
  }
  ll Getsum(int a,int b){
    return Dfs(1,a,b, 0,0,SIZE);
  }

  ll Getmin(int a,int b){
    return Dfs(2,a,b, 0,0,SIZE);
  }
  
};



int main(){
  
  int n,q;
  scanf("%d %d",&n,&q);
  segtree T(n);
  
  for(int i=0;i<q;i++){
    int type,a,b,c;
    scanf("%d %d %d",&type,&a,&b);
    if(type==0){
      scanf("%d",&c);
      T.Add(a,b+1,c);
    }else{
      printf("%lld\n", T.Getmin(a,b+1) );
    }
  }
  return 0;
}

