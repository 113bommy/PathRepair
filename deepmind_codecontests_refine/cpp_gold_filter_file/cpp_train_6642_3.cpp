#include<bits/stdc++.h>
using namespace std;
int main(){
  int s,a,b;cin>>s;
  a=s/100;
  b=s%100;
  if(a>0&&a<13){
    if(b>0&&b<13)cout<<"AMBIGUOUS"<<endl;
    else cout<<"MMYY"<<endl;
  }
  else{
    if(b>0&&b<13)cout<<"YYMM"<<endl;
    else cout<<"NA"<<endl;
  }
}
