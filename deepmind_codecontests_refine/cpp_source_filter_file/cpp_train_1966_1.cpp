#include <iostream>
#include <string>
using namespace std;
int d;
string map[105];
int n;
 
void visit() {
  int dx[4] = {0,1,0,-1};
  int dy[4] = {-1,0,1,0};
  int sum,  flg = 0;
  int x = 2,y = n;
  map[y][x] = ' ';
  int ab[4] = {2,2,2,2};
 
  while(1) {
    sum = 0;
    while(1) {
      if(map[y+dy[flg]*2][x+dx[flg]*2] != '#' && map[y+dy[flg]][x+dx[flg]] != ' ' ) {
    flg++;
    //  cout << sum << endl;
 
    break;
      }
       
      map[y+dy[flg]][x+dx[flg]] = ' ';
      y = y + dy[flg];
      x = x + dx[flg];
      sum++;
    }
    if(flg == 4) flg = 0;
    if(sum == 0) break;
    ab[0] = ab[1];
    ab[1] = ab[2];
    ab[2]  = sum;
    if(ab[0] == 1 && ab[2] == 1 && ab[1] == 1) break;
 
  }
}
 
 
int main() {
   
  cin >> d;
   
  for(int l=0;l<d;l++) {
     
    cin >> n;
 
    if(n == 1) {
      cout << "#" <<endl  ;
    if(l != d-1) cout << endl;
    continue;
    }   
 
    for(int i=0;i<=n+1;i++){
      map[i].resize(n+2);
      for(int j=0;j<=n+1;j++){
    map[i][j] = '#';
    if(i == 0 || j == 0 || i == n+1 || j == n+1) map[i][j] = '.';
      }
    }
     
     
    visit();
     
    for(int i=1;i<=n;i++){
      for(int j=1;j<map[i].size()-1;j++) {
    cout << map[i][j];
      }
      cout << endl;
    }
    if(l != d-1) 
      cout << endl;
     
  }
return 0
}