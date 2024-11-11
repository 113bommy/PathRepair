#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,a;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    if(a%2==0&&a%5!=0&&a%3!=0){
      cout<<"DENIED"<<endl;
      return 0;
    }
  }
  cout<<"APPROVED"<<endl;
  return 0;
}