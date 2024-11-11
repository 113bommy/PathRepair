#include<bits/stdc++.h.
using namespace std;
int main(){
  int n[12]={1,3,1,2,1,2,1,1,2,1,2,1};
  int a,b;
  cin>>a>>b;
  if(n[a-1]==n[b-1])
    cout<<"Yes";
  else
    cout<<"No";
}