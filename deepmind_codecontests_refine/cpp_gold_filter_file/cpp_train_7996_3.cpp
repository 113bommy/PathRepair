#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  long long k;
  cin>>s>>k;
  for(int i=0;i<k;i++){
    if(s[i]!='1'){
      cout<<s[i]<<endl;
      return 0;
    }
  }
  cout<<'1'<<endl;
  return 0;
}
      
  
  
