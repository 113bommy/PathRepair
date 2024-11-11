#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;cin>>s;
  int ss=0;
  for(int i=0;i<6;i++){
    if(s[i]=='1')ss++;
  }
  cout<<ss<<endl;
}
