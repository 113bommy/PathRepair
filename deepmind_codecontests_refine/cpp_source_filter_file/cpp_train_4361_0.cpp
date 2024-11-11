#include<iostream>
#include<cmath>
#include<vector>
#include<string>
typedef unsigned long long ull;
#define rep(i,a) for(int i=0;i<a;i++)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1);
const double inf = (int)1e8;

int main(void){
  char maze[3][3];
  while(cin>>mazze[0][0]){
    if(maze[0][0] == '0')break;
    rep(i,3)rep(j,3){
      if(i==0&&j==0)continue;
      cin>>maze[i][j];
    }
    bool find = false;
    rep(i,3)if(maze[0][i] == maze[1][i] && 
	       maze[1][i] == maze[2][i] && 
	       maze[0][i] != '+'){
      cout<<maze[0][i]<<endl;
      find = true;
    }
    if(find)continue;
    rep(i,3)if(maze[i][0] == maze[1][i] && 
	       maze[i][1] == maze[2][i] && 
	       maze[i][2] != '+'){
      cout<<maze[i][1]<<endl;
      find = true;
    }
    if(find)continue;
    if(maze[0][0] == maze[1][1] && 
       maze[1][1] == maze[2][2] &&
       maze[1][1] != '+'){
      cout<<maze[0][0]<<endl;
      continue;
    }else if(maze[2][0] == maze[1][1] && 
	     maze[1][1] == maze[0][2] &&
	     maze[2][0] != '+'){
      cout<<maze[1][1]<<endl;
      continue;
    }else{
      cout<<"NA"<<endl;
    }
    
  }
  return 0;
}