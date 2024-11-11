#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n,a,ans;
  ans=1;
  cin>>n;
  for(int i=0;i<n;i++){
  	cin>>a;
    if(a%2==0)ans=ans*2;
  }
  cout<<pow(3,n)-ans<<endl;
  return 0;
}