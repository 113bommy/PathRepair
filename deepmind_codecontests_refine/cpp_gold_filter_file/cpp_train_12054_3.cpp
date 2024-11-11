#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n=0,m;
  cin>>m;
  for(long long i=1;i<=m;i++){
    if(i%5!=0 && i%3!=0) n+=i;
  }
  cout<<n<<"\n";
  return(0);
}