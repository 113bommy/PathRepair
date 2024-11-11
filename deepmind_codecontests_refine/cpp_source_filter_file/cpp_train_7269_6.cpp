#include <iostream>
using namespace std;
int main(){
  long long int n,a;
  cin>>n>>a;
  
  for(int i=0;i=<n;i++){
    for(int m=0;m=<n;m++){
      int l=n-i-m;
      if(l>=0&&10000*i+5000*m+1000*l==a){
        cout<<i<<" "<<m<<" "<<l<<endl;
        return 0;
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
}