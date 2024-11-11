#include<iostream>
#include<algorithm>
using namespace std;
#define mod 100000
int w,h,memo[101][101][5];
int solve(int y,int x,int shine){
  if(y<0 || y >= h || x < 0 || x >= w) return 0;
  if(memo[y][x][shine]) return memo[y][x][shine];
  if(y == h - 1 && x == w - 1) return 1;
  if(!shine) //生きてる☆
    return memo[y][x][shine] = solve(y+1,x,1) + solve(y,x+1,2) % mod;
  if(shine == 1) // 死にそう^v^
    return memo[y][x][shine] = solve(y+1,x,1) + solve(y,x+1,4) % mod;
  if(shine == 2) // 死にそう^v^
    return memo[y][x][shine] = solve(y+1,x,3) + solve(y,x+1,2) % mod;
  if(shine == 3) //死んでる(・^・)
    return memo[y][x][shine] = solve(y+1,x,1) % mod;
  if(shine == 4) //死んでる(・^・)
    return memo[y][x][shine] = solve(y,x+1,2) % mod;
}
int main(){
  while(cin >> w >> h , w){
    fill_n(memo[0][0],101*101*4,0)
    cout << solve(0,0,0) % mod <<endl;
  }
}