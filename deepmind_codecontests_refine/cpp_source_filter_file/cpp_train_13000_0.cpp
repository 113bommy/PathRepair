nclude<iostream>
using namespace std;

char f[102][102];
char cnt_c[1];

void DFS(int y,int x){
  if(f[y][x]=='.'||f[y][x]==0||f[y][x]!=cnt_c[0])return;
  if(f[y][x]==cnt_c[0]){
    f[y][x]='.';
  }
  DFS(y+1,x);
  DFS(y-1,x);
  DFS(y,x+1);
  DFS(y,x-1);
}

int main(){
  int H,W;
  while(cin>>H>>W){
     if(H==0&&W==0)return 0;
      for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>f[i][j];
        }
      }
      int cnt=0;
      for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
          if(f[i][j]=='@'||f[i][j]=='#'||f[i][j]=='*'){
            cnt_c[0]=f[i][j];
            DFS(i,j);
            cnt++;
          }
        }
      }
      cout<<cnt<<endl;
    }
}

