#include <iostream>
using namespace std;
int main(){
  int n,k[112345],sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>k[i];
    sum+=k[i];
  }
  if(sum%2==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
