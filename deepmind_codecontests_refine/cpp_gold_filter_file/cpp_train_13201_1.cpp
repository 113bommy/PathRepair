#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b,ac=0,abc=0,bc=0;
  cin>>n>>a>>b;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(x<=a) ac++;
    else if(b<x) bc++;
    else abc++;
  }
  int minnum=min(ac,bc);
  minnum=min(minnum,abc);
  cout<<minnum<<endl;
}