#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum=0,tmp;
  cin >> n;
  for(int i=1;i<=n;i++){
    sum+=i;
    if(sum>=n){
      tmp=sum-n;
      break;
    }
  int a=0;
  for(int i=1;i<=n;i++){
    if(a==n)break;
    if(i!=tmp){
      cout << i << endl;
      a+=i;
    }
  }
  return 0;
}