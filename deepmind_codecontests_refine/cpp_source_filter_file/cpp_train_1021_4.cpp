#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<char>s[55][55];
  bool ok = true;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> s[i][j];
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s[i][j]=='.')continue;
      if(s[i][j]=='#'&&s[i-1][j]!='#'&&s[i][j+1]!='#'&&s[i][j-1]!='#'&&s[i+1][j]!='#')
      ok=false;
    }
  }
  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;
}