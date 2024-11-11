#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  string k="";
  for(int i=0;i<5;i++){
    k += "hi";
    if(s==k){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
