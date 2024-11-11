#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define INF 2147483647
pair<int,int> data[4000001];
int n,_n;
void init(int n){
  _n=1;
  while(_n<1100000)_n*=2;
}
void update(int i,int x){
  int p=i;
  i+=_n-1;
  data[i].f+=x;
  data[i].s=p+1;
  while(i>0){
    i=(i-1)/2;
    if(data[2*i+1].f==data[2*i+2].f){
      if(data[2*i+1].s<data[2*i+2].s)
        data[i]=data[2*i+1];
      else data[i]=data[2*i+2];
    }
    else if(data[2*i+1].f>data[2*i+2].f)
      data[i]=data[2*i+1];
    else data[i]=data[2*i+2];
  }
}
int main(){
  int q;
  cin>>n>>q;
  init(n);
  while(q--){
    int a,b;
    cin>>a>>b;
    update(a-1,b);
    cout<<data[1].second<<' '<<data[1].first<<endl;
  }
}