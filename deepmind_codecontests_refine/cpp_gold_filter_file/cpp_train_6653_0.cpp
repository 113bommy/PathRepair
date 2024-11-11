#include<iostream>
using namespace std;
int w,h;
char tail[21][21];
int a[]={-1,0,1,0};
int b[]={0,1,0,-1};
int cnt=0;
void func(int x,int y);
int main(){
  int sx,sy;
  while(1){
    cin>> w>> h;
      if(w==0&&h==0) break;
    cnt=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>> tail[i][j];
	if(tail[i][j]=='@'){
	  sx=j;
	  sy=i;
	}
      }
    }
    func(sx,sy);
    cout<< cnt<< endl;
  }
}

void func(int x,int y){
  tail[y][x]='#';
  cnt++;
  for(int i=0;i<4;i++){
    int nx=x+a[i];
    int ny=y+b[i];
    if(nx>=0 && nx<w && ny>=0 && ny<h && tail[ny][nx]!='#'){
      func(nx,ny);
    }
  }
}