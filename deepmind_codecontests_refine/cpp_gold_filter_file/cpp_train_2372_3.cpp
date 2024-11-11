#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,k;
  string s;
  cin>>a>>s;
  long long color , l=0, r=0,g=0,b=0;
  for(int i=0;i<a;i++){
    if(s.at(i)=='R')r++;
    else if(s.at(i)=='G')g++;
    else b++;
  }
  color=r*g*b;
  for(int i=0;i<a;i++){
    for(int j=i+1;j<a;j++){
      k=2*j-i;
      if(k>=a || s.at(i)==s.at(k) || s.at(j)==s.at(k) || s.at(i)==s.at(j))continue;
      l++;      
    }
  }
  cout <<color - l<<endl;
}