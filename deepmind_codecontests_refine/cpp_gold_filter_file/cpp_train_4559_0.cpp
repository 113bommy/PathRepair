#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,M;cin>>A>>B>>M;
  vector<int> a(A);
  vector<int> b(B);
  for(int i=0;i<A;i++) cin>>a[i];
  for(int i=0;i<B;i++) cin>>b[i];
  int mina,minb;
  mina=*min_element(a.begin(),a.end());
  minb=*min_element(b.begin(),b.end());
  int ans=mina+minb;
  for(int i=0;i<M;i++){
    int a1,b1,discount;
    cin>>a1>>b1>>discount;
    ans=min(ans,a[a1-1]+b[b1-1]-discount);
  }
  cout<<ans<<endl;
}
