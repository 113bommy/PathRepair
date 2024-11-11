#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;cin>>s>>t;
  int n=s.size(),m=t.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s.at(i-1)==t.at(j-1))dp.at(i).at(j)=dp.at(i-1).at(j-1)+1;
      else dp.at(i).at(j)=max(dp.at(i).at(j-1),dp.at(i-1).at(j));
    }
  }
  int i=n,j=m;string LCS;
  while(LCS.size()<dp.at(n).at(m)){
    if(dp.at(i).at(j)==dp.at(i-1).at(j))i--;
    else if(dp.at(i).at(j)==dp.at(i).at(j-1))j--;
    else{LCS=s.at(i-1)+LCS;i--;j--;}
  }
  cout<<LCS<<endl;
}