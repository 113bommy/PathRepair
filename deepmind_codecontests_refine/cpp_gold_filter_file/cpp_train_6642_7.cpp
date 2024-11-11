#include<bits/stdc++.h>
using namespace std;
int main(){
  int S,L,R;
  cin>>S;
  L=S/100;
  R=S%100;
  if(L>=1&&L<=12){
    if(R>=1&&R<=12)cout<<"AMBIGUOUS"<<endl;
    else cout<<"MMYY"<<endl;
  }else{
    if(R>=1&&R<=12)cout<<"YYMM"<<endl;
    else cout<<"NA"<<endl;
  }
  return 0;
}
