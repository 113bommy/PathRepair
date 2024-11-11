#include <bits/stdc++.h>
using namespace std; 
int main(){
  int H,W;
  char a;
  cin>>H>>W;
  for(int i=0;i<H+2;i++){
    for(int j=0;j<W+2;j++){
      if(i==0||i==H+1||j==0||j==W+1)cout<<"#";
      else{
        cin>>a;
        cout<<a
      }
    }
    cout<<endl;
  }
}