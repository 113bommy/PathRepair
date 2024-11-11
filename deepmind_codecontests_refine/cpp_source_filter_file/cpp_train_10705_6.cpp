#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i;
  cin>>n;
  int sum=0;
  for(i=0,i<10;i++){
    sum+=(n/pow(10,i))%10;
  }
  if(n%sum==0)cout<<"Yes";
  else cout<<"No";
}