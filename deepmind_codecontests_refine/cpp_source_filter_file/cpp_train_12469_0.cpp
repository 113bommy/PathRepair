#include <bits/stdc++.h>
using namespace std;

int main(){
  int S=0;
  int D;
  cin >> D;
  vector<int>c(27);
  for(int i=1;i<27;i++){
    cin >> c[i];
  }
  vector<vector<int>>s(D+1,vector<int>(27,0));
  for(int i=1;i<=D;i++){
    for(int j=1;j<27;j++){
      cin >> s[i][j];
    }
  }
  vector<int>t(D);
  for(int i=1;i<=D;i++){
    cin >> t[i];
  }
  vector<int>lastDi(27);
  for(int i=1;i<=D;i++){
    for(int j=1;j<27;j++){
      if(t[i]==j){
        lastDi[j]=i;
        S+=s[i][j];
      }
      S-=c[j]*(i-lastDi)
    }
    cout << S << endl;
  }
}