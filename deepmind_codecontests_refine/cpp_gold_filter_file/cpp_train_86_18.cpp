#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(2*max(max(a,c),b)==a+b+c){cout<<"Yes";}
  else{cout<<"No";}
}