#include<iostream>
using namespace std;
using ll=long long;
int main(){
  ll x,k,d;
  cin>>x>>k>>d;
  x=abs(x);
  ll straight=min(k,x/d);
  k-=straight;
  x-=straight*d;
  if(k%2==0){
    cout<<x<<endl;
  }
  else{
    cout<<d-x<<endl;
  }
  return 0;
}
