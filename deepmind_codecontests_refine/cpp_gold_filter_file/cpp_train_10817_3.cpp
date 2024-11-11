#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0){return 0;}
    int s[n];
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
    sort(s,s+n);
    int ans=0;
    for(int i=1;i<n-1;i++){
      ans+=s[i];
    }
    cout<<ans/(n-2)<<endl;
  }
  return 0;}