#include<bits/stdc++.h>
using namespace std;
int main(){
  long int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout << max(b*d,max(a*c,max(a*d,(b*c))))<<endl;
  }