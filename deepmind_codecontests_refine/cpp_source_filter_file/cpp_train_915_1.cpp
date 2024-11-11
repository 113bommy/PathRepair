#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt;
  double c=0,d=1000000;
  cin>>n;
  double a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    c+=a[i];
  }
  c/=n;
  for(int i=0;i<n;i++){
    if(d>abs(c-a[i]){
      d=abs(c-a[i]);
      cnt=i;
    }
  }
  cout<<cnt;
}