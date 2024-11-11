#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;cin>>s;
  int count=1;
  while(s>4|s==3){
    if(s%2==0)s/=2;
    else s=3*s+1;
    count++;}
  cout<<count+3;}