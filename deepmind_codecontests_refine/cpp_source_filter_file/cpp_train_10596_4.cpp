#include<iostream>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int ans=0;
  for(n>0){
    n/=k;
    ans=++;
  }
  cout<<ans<<endl;
}
