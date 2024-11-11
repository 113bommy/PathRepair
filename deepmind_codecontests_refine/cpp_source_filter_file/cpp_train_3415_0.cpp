#include<bits/stdc++.h>
using namespace std;
int main(){
int N,L;
  cin>>N>>L;
  int a=L+N-1;
  int b;
if(a<=0){
b=a;
}
  else if(L>=0){
  b=L;
  }
  else{
  b=0
  }
  cout<<(a+L)*(a-L+1)/2-b<<endl;
}