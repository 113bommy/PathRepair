#include <bits/stdc++.h>
using namespace std;

int main() {
  int dx[8]={1,1,1,0,0,-1,-1,-1};
  int dy[8]={1,0,-1,1,-1,1,0,-1};
  int H,W ;
  cin >> H >> W ;
  string S[H];
  for (int i=0;i<H;i++) cin >> S[i];
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) {
      if(S[i][j]=='.') {
        int count=0;
        for (int k=0;k<8;k++) {
          int x=i+dx[k];
          int y=j+dy[k];
          if (0<=x &&x<H &&0<=y&&y<W&&S[x][y]='#') count++;
        }
        S[i][j]='0'+count ;
      }
    }
  }
  for (int i=0,i<H,i++) cout << S[i] <<endl;
}
