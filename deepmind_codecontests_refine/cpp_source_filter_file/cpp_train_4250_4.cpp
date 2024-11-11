#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin>>A>>B>>K;
  vector<int> s(0,0);
  for(int i=100; i>0; --i){
    if(A%i==0 && B%i==0) s.push_back();
  }
  cout<<s.at(K-1)<<endl;
}
