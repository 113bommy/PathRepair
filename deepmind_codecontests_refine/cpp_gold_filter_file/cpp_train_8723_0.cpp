#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,i,wa=0,hiku=0,b;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    wa+=a[i];
    if(i%2==1){
      hiku+=a[i];
    }
  }
  b=(wa/2)-hiku;
  for(i=0;i<n;i++){
    cout<<2*b<<" ";
    b=a[i]-b;
  }
}
    
