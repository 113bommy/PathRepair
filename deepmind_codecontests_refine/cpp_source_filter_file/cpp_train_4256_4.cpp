#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans=0,n,array[200];
  cin>>n;
  for(int i=0;i<2n;i++){
    cin>>array[i];
  }
  sort(array,array+2n);
  for(int i=0;i<2n;i+=2){
    ans+=array[i];
  }
  cout<<ans<<endl;
}