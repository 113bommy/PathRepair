#include <iostream>
using namespace std;
  
int F[105][105];
int xg,yg;
  
  
void DFS(int Y,int X,int c){
  if(F[Y][X] != c){
    return;
  }
  
  F[Y][X] = -2000;
  DFS(Y-1,X  ,c);
  DFS(Y  ,X+1,c);
  DFS(Y+1,X  ,c);
  DFS(Y  ,X-1,c);
}
  
  
int main(){
  int w,h,xs,ys,n;
  while(1){
    cin >> w >> h;
    if(w == 0 && h == 0)
      break;

      
    cin >> xs >> ys >> xg >> yg >> n;
    int c[n],d[n],x[n],y[n],ca;
    for(int i=0;i<n;i++){
      cin >> c[i] >> d[i] >> x[i] >> y[i];
    }
    for(int i=0;i<n;i++){
      if(c[i] == 0)
        ca = 10
      else if(i == n-1)
        c = 0:
    }
    for(int i=0; i<102; i++){
          for(int j=0; j<102; j++){
            F[i][j]=ca;
          }
    }
    for(int i=0;i<n;i++){
      if(d[i] == 0){
        for(int j=0;j<4;j++){
          F[x[i]+j][y[i]] = c[i];
          F[x[i]+j][y[i]+1] = c[i];
        }
      } else {
        for(int j=0;j<4;j++){
          F[x[i]][y[i]+j] = c[i];
          F[x[i]+1][y[i]+j] = c[i];
        }
      }
    }
 
  DFS(xs,ys,F[xs][ys]);
  
  if(F[xg][yg] == -2000){
    cout << "OK" << endl;
  } else {
    cout << "NG" <<endl;
  }
  }
}
