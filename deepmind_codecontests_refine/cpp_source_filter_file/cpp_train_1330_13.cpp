#include <bits/stdc++.h>
using namespace std;

int main(){
ll a;
cin>>a;
  ll b;
  b=a%10;
  if(b==3) cout<<"bon";
else if(b==0 || b==1 || b==6 || b==8) cout<<"pon";
  else cout<<"hon";
  
}