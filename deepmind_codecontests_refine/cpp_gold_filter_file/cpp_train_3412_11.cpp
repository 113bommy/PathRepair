#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int n=7, k,count=1;
  cin>>k;
  while(n%k){
  n=(n%k)*10+7;
  count++;
  if(count>=1000000){count=-1;break;}
  }
  cout<<count;
return 0;
}