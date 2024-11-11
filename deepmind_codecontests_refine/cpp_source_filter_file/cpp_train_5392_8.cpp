#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  if(n%2==1) cout<<"No";
  else{
    string t=s;
    t=substr(0,t/2);
    t=t+t;
    if(t==s) cout<<"Yes";
    else cout<<"No";
  }
}