#include <iostream>
using namespace std;

int main(){
  int n;
  int a=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    if(k!=i+1) a += 1;
  }
  
  if(a>2) cout<<"NO"<endl;
  else cout<<"YES"<<endl;
  return 0;
}