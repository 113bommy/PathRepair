#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int num=1e9;
  for(int i=0;i<=100000;i++){
    int sum=i*2c+a*max(x-i,0)+b*max(y-i,0);
    num=min(sum,num);
  }
  cout<<num<<endl;
}