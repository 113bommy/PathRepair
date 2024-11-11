#include<bits/stdc++.h>
using namespace std
int main(void){
  
  int a,n,i; 
  cin>>n;
  string s="APPROVED";
  for(i=0;i<n;i++){
    cin>>a;
  	if((a%2==0))if((a%3!=0)&&(a%5!=0))s="DENIED";
    
  }
  cout<<s;
}