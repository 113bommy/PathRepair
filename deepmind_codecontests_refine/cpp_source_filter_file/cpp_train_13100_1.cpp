#include <bits/stdc++.h>
using namespace std;
int n,a[100000],num;
long long ans+1;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int i=n-1;i;i--){
    if(a[i]==a[i-1]){
      ans*=a[i];
      i--;
      num++;
    }
    if(num==2){
      cout<<ans;
      return 0;
    }
  }
  cout<<0;
  return 0;
}