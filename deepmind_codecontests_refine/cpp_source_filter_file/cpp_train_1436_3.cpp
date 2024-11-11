#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m=0;cin>>n;
  vector<pair<string,int>>a(n);
  for(int i=0;i<n;i++)cin>>a.at(n).first>>a.at(n)second;
  string s;cin>>s;
  for(int i=0;i<n;i++){
    if(i<n-1 && a.at(i).first==s){
      for(int j=i+1;j<n;j++)m+=a.at(j).second;
      break;
    }
  }
  cout<<m<<endl;
}
