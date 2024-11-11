#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,a=0;string s;cin>>n>>k>>s;
  for(int i=0;i<N-1;i++){
    if(s.at(i)==s.at(i+1))a++;
  }
  cout<<min(k*2+a,n-1)<<endl;
}
