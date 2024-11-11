#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  cout<<c-min(c,a-b)<<endl;
}