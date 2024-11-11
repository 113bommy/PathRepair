#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int r=0,l=0;
  string s;
  cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      l++;
    }else{
      if(l>0){
        l--;
      }else{
        r++;
      }
    }
  }
  for(int i=0;i<r;i++){
    cout<<'(';
  }
  cout<<s;
  for(int i=0;i<l;i++){
    cout<<')';
  }
}