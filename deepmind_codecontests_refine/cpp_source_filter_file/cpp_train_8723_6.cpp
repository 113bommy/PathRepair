#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,i,wa=0,hiku=0,a;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    wa+=a[i];
    if(i%2==1){
      hiku+=a[i];
    }
  }
  a=(wa/2)-hiku;
  for(i=0;i<n;i++){
    cout<<2*a<<" ";
    a=a[i]-a;
  }
}
    