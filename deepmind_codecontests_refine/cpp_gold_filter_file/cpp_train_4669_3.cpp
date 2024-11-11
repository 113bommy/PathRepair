#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int h,k;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(h<a){
      h=a;
      k=b;
    }
  }
  cout<<h+k<<endl;
}
