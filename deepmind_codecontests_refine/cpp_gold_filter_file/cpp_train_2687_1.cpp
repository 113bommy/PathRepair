#include<iostream>
using namespace std;
int main(){
  string s;cin>>s;
  int a=0,b=0;
  for(char p:s){
    if(p=='A'||p=='C'||p=='T'||p=='G'){a++;b=max(a,b);}
    else a=0;
  }
  cout<<b<<endl;
}
