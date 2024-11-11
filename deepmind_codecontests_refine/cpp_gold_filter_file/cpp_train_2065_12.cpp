#include<iostream>
using namespace std;

int main(){
  int n;
  int s=100;
  cin>>n;
  for(int i=0;i<n;i++){
    int a;
    int v=0;
    cin>>a;
    while(a%2==0){
      a /= 2;
      v++;
    }
    s=min(v,s);
  }
  cout<<s<<endl;
  return 0;
}
  
    