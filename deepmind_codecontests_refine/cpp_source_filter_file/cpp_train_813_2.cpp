#include<bits/stdc++.h>
using namesapce std;

string s[52];

int main(void){
  int h, w;
  cin >> h >> w;
  for(int j=0;j<=w+1;j++) s[0] += '.';
  for(int i=0;i<h;i++){
    cin >> s[i];
    s[i] = '.' + s[i] + '.';
  }
  s[h+1] = s[0];
  
  for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
    if (s[i][j]=='.'){
      int cnt = 0;
      for(int k=-1;k<2;k++)for(int l=-1;l<2;l++){
        if (s[i+k][j+l]=='#') cnt++;
      }
      s[i][j] = '0' + cnt;
    }    
  }
  
  for(int i=1;i<=h;i++) cout << s[i].substr(1, w) << endl;
  return 0;  
}  