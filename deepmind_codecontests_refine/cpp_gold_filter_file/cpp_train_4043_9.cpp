#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if((a>c)||((a+b)<c))cout << "NO";
  else cout <<"YES";
}