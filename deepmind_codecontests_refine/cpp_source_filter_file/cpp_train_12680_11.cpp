#include<iostream>
#include<string>
using namespace std;
int main(){
 string n;cin>>n;
  int a=0,b=0;
  for(int i=0;i<n.length();i++){
    if(n[i]=='o')a++;
    else b++;
    }
  if(b>7){cout<<"NO";}
  else cout"YES";
}