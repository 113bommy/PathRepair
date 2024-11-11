#include<bits/stdc++.h>
using namespace std;
 
int main(){
  string a;
  cin>>a;
  int b=0;
  for(int i=0;i<a.size();i++){
    if(a.at(i)=='x')
      b++;
  }
  if(b<8)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}
