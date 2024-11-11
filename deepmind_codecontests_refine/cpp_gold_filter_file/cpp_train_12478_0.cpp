#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;cin>>n;
  string s,t;
  cin>>s>>t;
  for(int i=0;i<n;i++){
    if(s.substr(i,n-i)==t.substr(0,n-i)){
      cout<<i+n<<endl;
      return 0;
    }
  }
  cout<<2*n<<endl;
  return 0;
}