#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin>>N>>A>>B;
  vector<vector<vector<int>>> dp(N,vector<vector<int>>(401,vector<int>(401,5000)));
  int a,b,c;
  cin>>a>>b>>c;
  dp.at(0).at(0).at(0)=0,dp.at(0).at(a).at(b)=c;
  for(int i=1;i<N;i++){
    cin>>a>>b>>c;
    for(int j=0;j<401;j++){
      for(int k=0;k<401;k++){
        if(j>=a&&k>=b){
          dp.at(i).at(j).at(k)=min(dp.at(i-1).at(j).at(k),dp.at(i-1).at(j-a).at(k-b)+c);
        }
        else{
          dp.at(i).at(j).at(k)=dp.at(i-1).at(j).at(k);
        }
      }
    }
  }
  int X=A,Y=B,Z=5000;
  while(X<=400&&Y<=400){
    Z=min(Z,dp.at(N-1).at(X).at(Y));
    X+=A,Y+=B;
  }
  if(Z==5000){
    cout<<"-1"<<endl;
  }
  else{
    cout<<Z<<endl;
  }
                        
}