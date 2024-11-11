#include<iostream>
#include<map>
using namespace std;

int main(){
  int n;cin>>n;
  map<int,int>a;
  for(int i=0,tmp;i<n;i++){
    cin>>tmp;a[tmp]++;
    if(a[tmp]>1){cout<<"NO"endl;return 0;}
  }
  cout<<"YES"<<endl;
  return 0;
}