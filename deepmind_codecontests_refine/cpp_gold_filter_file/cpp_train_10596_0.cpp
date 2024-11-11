#include<iostream>
using namespace std;
 
int main(){
  int n,k;
  cin>>n>>k;
  int a=0;
  while(n>0){
    n/=k;
    a++;
  }
  cout<<a<<endl;
}
