#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int m=max({a,b,c});
  cout<<a+b+c+9*m<<endl;
}