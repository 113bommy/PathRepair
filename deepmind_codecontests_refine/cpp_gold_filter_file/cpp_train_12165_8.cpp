#include<bits/stdc++.h>
using namespace std;
int main() {
  long long N,K;cin>>N>>K;long long M=0;
  map<long long,long long>mp;
  for(int X=0;X<N;X++){
    int A,B;cin>>A>>B;
    mp[A]+=B;
  }
  for(auto p:mp){
    long long A=p.first;long long B=p.second;M+=B;
    if(M>=K){
      cout<<A<<endl;break;
    }
  }
}