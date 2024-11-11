#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;cin>>s;
  int s=0;
  for(int i=0;i<6;i++){
    if(s[i]=='1')s++;
  }
  cout<<s<<endl;
}
