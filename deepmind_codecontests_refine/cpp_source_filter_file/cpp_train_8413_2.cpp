#include<bits/stdc++.h>
using namespace std;
long long q,x,y,i=0; 
main(){
  cin>>q;
  while(i<q){
    cin>>x>>y;
    if(x>y)swap(x,y);
    long double k=sqrt(x*y-0.75)-x+0.5;
    cout<<(l)(x-1+k+(x*y-1)/(x+k))-(x!=y)<<endl;
    i++;
  }
}
