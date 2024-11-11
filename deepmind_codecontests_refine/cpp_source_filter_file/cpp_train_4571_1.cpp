#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(co)co.begin(),co.end()
int main()
{
  int n; cin >> n;
  vector<vector<int>> table(3, vector<int>(n));
  vector<int> score(n);
  rep(i,n)rep(j,3)cin>>table[j][i];
  rep(j,3)rep(i,n)
  {
    if(count(all(table[j]), table[j][i]) == 1)score[i]+=table[j][i];
  }
  rep(i,n)cout>>score[i]>>endl;
  return 0;
}