#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll x,y,i,j;
  cin >> x;
  for(i=-200;i<=200;i++){
    for(j=-200;j<=200;j++){
      y=pow(i,5)-pow(j,5);
      if(x==y){
        a=i;
        b=j;
      }
    }
  }
  cout << a << " " << b;
}