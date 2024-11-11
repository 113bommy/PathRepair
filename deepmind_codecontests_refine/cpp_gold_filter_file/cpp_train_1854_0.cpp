#include<bits/stdc++.h>
using namespace std;

int main(){
  string n; cin>>n;
  string ans="Good";
  for(int i=0;i<3;i++)if(n[i]==n[i+1])ans="Bad";
  cout<<ans<<endl;
}