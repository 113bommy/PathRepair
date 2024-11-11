#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  string s[100];
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  sort(s,s+n);
  for(int i=0;i<n;i++){
    cout<<s[i];
  }
  cout<<endl;
}