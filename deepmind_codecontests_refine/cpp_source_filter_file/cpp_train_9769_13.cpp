#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a;
  cin>>N;
  a=N%1000
  if (N%1110<10|N%1111==0|a%111==0){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}