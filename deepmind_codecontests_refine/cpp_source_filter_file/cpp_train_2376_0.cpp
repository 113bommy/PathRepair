#include <iostream>
#include <vector>
using namespace std;

struct point{
  int i,j,k,l;
};

int main(){
  int h,w;
  cin >> h >> w;
  int m[h][w];
  vector<point> ret;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> m[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w-1;j++){
      if(m[i][j]%2==1){
        m[i][j]--;
        m[i][j+1]++;
        ret.push_back({i+1,j+1,i+1,j+2});
      }
    }
  }
  for(i=0;i<h-1;i++){
    if(m[i][w-1]%2==1){
      m[i+1][w-1]++;
      ret.push_back({i+1,w,i+2,w});
    }
  }
  cout << (int)ret.size() << endl;
  for(auto &x:ret){
    printf("%d %d %d %d\n",x.i,x.j,x.k,x.l);
  }
}