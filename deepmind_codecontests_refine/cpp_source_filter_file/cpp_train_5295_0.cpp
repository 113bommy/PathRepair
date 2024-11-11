#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool a=false,b=false;
  if(s.size()%2==0){
    a=true;
  
  if(s[0]==s[s.size()-1]){
    b=true;
  }
  if(a^b){
    cout << "Second" << endl;
  }
  else{
    cout << "First" << endl;
  }
}