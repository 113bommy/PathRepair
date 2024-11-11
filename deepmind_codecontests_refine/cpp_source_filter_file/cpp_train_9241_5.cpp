#include<bits/std++.h>
using namespace std;
int main(){
  int k; string s;
  cin>>k>>s;
  if(s.length()<=k) cout<<s;
  else {
    cout<<s.substr(0,k);
  }
}