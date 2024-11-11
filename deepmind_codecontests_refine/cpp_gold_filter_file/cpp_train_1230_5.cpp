#include <bits/stdc++.h>
using namespace std;

int main(){
  string n;cin>>n;int a=0;
  for(int i;i<4;i++){
    if(n[i]=='+')a++;
    else{a--;}}
  cout<<a<<endl;}