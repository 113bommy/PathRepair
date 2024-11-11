#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<int> ac(n,0);
  vector<int> count(n,0);
  for(int i=0;i<n-1;i++){
    if(s[i]=='A'&&s[i+1]=='C'){ac[i+1]=1;}
    count[i+1]+=count[i]+ac[i+1];
  }
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<count[r-1]-count[l-1]<<endl;
  }
}