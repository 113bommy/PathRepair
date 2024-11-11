#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,ans=0; cin>>n;
  long long sumD=0,lack=0;
  long long a[n],b[n],diff[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
    diff[i]=b[i]-a[i];
    sumD+=diff[i];
  }
  sort(diff,diff+n);
  if(sumD<=0){
    for(int i=0;i<n;i++){
      if(diff[i]>0){
        ans++;
        lack+=diff[i];
      }
    }
    for(int i=0;i<n;i++){
      if(lack<=0){
        break;
      }
      ans++;
      lack+=diff[i];
    }
  }
  if(sumD>0){
    cout<<-1;
  }else{
    cout<<ans;
  }
}