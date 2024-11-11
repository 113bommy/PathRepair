#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  string s="";
  while(N!=0){
  if(abs(N)%2==0){
  s='0'+s; N/=-2;
  }else{
  s='1'+s; N=(1-N)/2;
  }
  }if(s=="")
    cout<<0<<endl;
  else
    cout<<s<<endl;
    return 0;
}
