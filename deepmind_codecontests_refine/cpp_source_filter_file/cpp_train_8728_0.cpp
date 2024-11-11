#include<bits/stdc++.h>
using namespace std;
long long ll;
int main (){
  ll x,y;
  cin >> x >> y;
  if(abs(x-y)<=1){
    cout<<"Brown"<<endl;
  }else{
    cout<<"Alice"<<endl;
  }
  return 0;
}
