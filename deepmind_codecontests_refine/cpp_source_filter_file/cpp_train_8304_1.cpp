#include<iostream>
using namespace std;

int main(){
  int H,N,sum=0,A;
  cin>>H,N;
  for(int i=0;i<N;i++){
    cin>>A;
    sum+=A;
  }
  if(sum<H){cout<<"No";}
  else{cout"Yes";}
}