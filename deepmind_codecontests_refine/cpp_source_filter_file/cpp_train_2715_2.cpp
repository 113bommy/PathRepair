#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define MAX_V 1<<17
#define INF INT_MAX

using namespace std;

int dat[MAX_V*2],sz;

void update(int k,int x){
  k+=sz-1;
  dat[k]=x;
  while(k>0){
    k=(k-1)/2;
    dat[k]=min(dat[k*2+1],dat[k*2+2]);
  }
}

int query(int a,int b,int k,int l,int r){
  if(r<=a || b<=l)return INF;
  if(a<=l && r<=b)return dat[k];

  int vl=query(a,b,k*2+1,l,(l+r)/2);
  int vr=query(a,b,k*2+2,(l+r)/2,r);
  return min(vl,vr);
}

int main(void){

  fill(dat,dat+MAX_V*2,INF);

  int n,q;
  cin >> n >> q;
  sz=1;
  while(sz<n)sz*=2;

  while(q--){
    int com,x,y;
    cin >> com >> x >> y;
    if(com)cout << query(x,y+1,0,0,sz) << endl;
    else update(x,y);
  }

  return 0;
}