#include <iostream>
using namespace std;
  
int F[105][105];
int xg,yg,w,h;
  
  
void DFS(int Y,int X,int c){
  if(F[Y][X] != c){
    return;
  }
  
  F[Y][X] = -1;
  DFS(Y+1,X  ,c);
  DFS(Y-1  ,X,c);
  DFS(Y,X+1  ,c);
  DFS(Y  ,X-1,c);
}
  
  
int main(){
  int xs,ys,n;
  while(1){
    cin >> w >> h;
    if(w == 0 && h == 0)
      break;
for(int i=0; i<105; i++){
      for(int j=0; j<105; j++){
        F[i][j] = 10;
      }
    }
      
    cin >> xs >> ys >> xg >> yg >> n;
  
  
    for(int i=0;i<n;i++){
      int c,d,x,y;
      cin >> c >> d >> x >> y;

      if(d == 0){
        for(int j=0;j<4;j++){
          F[x+j][y] = c;
          F[x+j][y+1] = c;
        }
      } else {
        for(int j=0;j<4;j++){
          F[x][y+j] = c;
          F[x+1][y+j] = c;
        }
      }
    }
  if(F[xs][ys] == 10){
cout << "NG" << endl;
continue;
  DFS(xs,ys,F[xs][ys]);
  
  if(F[xg][yg] == -1){
    cout << "OK" << endl;
  } else {
    cout << "NG" <<endl;
  }
  }
}
