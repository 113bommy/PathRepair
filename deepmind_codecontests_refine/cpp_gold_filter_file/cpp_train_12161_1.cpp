#include<iostream>
using namespace std;

int main(){
  int n,m,k,c=0; cin>>n>>m>>k;
  int b[m];
  for(int i=0;i<m;i++) cin>>b[i];
  
  for(int i=0;i<n;i++){
    int s=0;
    for(int j=0;j<m;j++){
      int k; cin>>k;
      s += k*b[j];
    }
    if(s+k>0) c++;
  }
  
  cout<<c<<endl;
  return 0;
}