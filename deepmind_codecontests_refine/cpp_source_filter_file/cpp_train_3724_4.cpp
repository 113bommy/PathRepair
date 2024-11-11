#include<iostream>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s[s.size()-1]!="s")
    cout<<s<<"s"<<endl;
  else
    cout<<s<<"es"<<endl;
}