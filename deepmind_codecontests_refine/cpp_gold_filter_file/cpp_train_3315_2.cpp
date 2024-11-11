#include<bits/stdc++.h>
using namespace std;

int main(void){

  int a,b;
  cin>>a>>b;
  cout<<(a%3==0||b%3==0||(a+b)%3==0?"Possible":"Impossible");
}
