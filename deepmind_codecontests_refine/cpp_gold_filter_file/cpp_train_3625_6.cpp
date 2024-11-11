#include<bits/stdc++.h>
using namespace std;

int main(){
  int nu=0,ma=0;
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]>='A'&&s[i]<='Z'){
      ma++;
    }
  }
  for(int i=2;i<=s.size()-2;i++){
    if(s[i]=='C'){
      nu++;
    }
  }
  if(s[0]=='A'&&nu==1&&ma==2){
    cout<<"AC"<<endl;
  }
  else{
    cout<<"WA"<<endl;
  }
}
    
  
  

