#include <iostream>
#include <string>
using namespace std;

int N;
string s,t;

int solve(){
  for (int i=0;i<N;++i){
    if(s.substr(i)==t.substr(0,N-i))return i+N;
  }
  return N*2;
}

int main(){
  cin >>N>>s>>t;
  cout<<solve()<<endl;
}