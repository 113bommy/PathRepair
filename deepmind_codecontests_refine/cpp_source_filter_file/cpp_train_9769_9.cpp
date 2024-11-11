include<iostream>
include<string>
using namespace std;

int main(){
string s;
  cin>>s;
  if(s[1]==s[2]&&(s[0]==s[1]||s[3]==s[0])){
    cout<<"Yes"<<endl;
  }else cout<<"No"<<endl;
}