#include<bits/stdc++.h>
using namespace std;
typedef long long
main(){
  l q;cin>>q;
  for(l i=0;i<q;i++){
    l x,y;
    cin>>x>>y;
    if(x>y)swap(x,y);
    long double k=sqrt(x*y-0.75)-x+0.5;
    cout<<(l)(x-1+k+(x*y-1)/(x+k))-(x!=y)<<endl;
  }
}
