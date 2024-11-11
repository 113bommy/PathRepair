#include<iostream>
using namepsace std;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;++i){
    int x;
    cin>>x;
    if(x%2==1&&i%2==0)
      ans++;
  }
  cout<<ans;
}