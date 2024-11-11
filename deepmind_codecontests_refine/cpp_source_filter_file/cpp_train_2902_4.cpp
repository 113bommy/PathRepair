#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int a,b,k=0,i,j=0;
  
  while(1){
    cin>>a>>b;
    if(a==0&&b==0)break;
   
    if(j) cout<<endl;
    k=0;
    for(i=a;i<=b;i++){
      if(i%4==0&&i%100!=0){cout<<i<<endl;k++;}
      if(i%400==0){cout<<i<<endl;k++}
    }    
    if(k==0)cout<<"NA"<<endl;
    j=1;  
  }
return 0;
}