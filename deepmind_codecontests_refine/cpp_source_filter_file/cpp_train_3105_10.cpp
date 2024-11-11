#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,x=0;cin>>N;
  vector<int>C(N);
  cin>>C.at(0)
  for(int i=1;i<N;i++){
    cin>>C.at(i);
    if(C.at(i)==C.at(i-1)){
      x++;C.at(i)=0;
    }
  }
  cout<<x<<endl;
}