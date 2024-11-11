#include<bits/stdc++.h>
using namespace std;

long gcd(long a,long b)return (a%b==0)?b:gcd(b,a%b);
int main(){
  long i,N,M,p;
  cin>>N>>M;
  string s,t;
  cin>>s>>t;
  p=gcd(N,M);
  N/=p;M/=p;
  for(i=0;i<p;i++){
    if(s[i*N]!=t[i*M]){cout<<"-1"<<endl;return 0;}
  }
  cout<<N*M*p<<endl;
  return 0;
}