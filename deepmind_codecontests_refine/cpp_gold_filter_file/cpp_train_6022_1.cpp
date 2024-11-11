#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<vector<int>> A(3,vector<int>(N));
  for(int i=0;i<3;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
    }
    sort(A[i].begin(),A[i].end());
  }
  vector<vector<long long>> cumsum(3,vector<long long>(N+1)); // count, cumsum
  for(int j=0;j<N;j++) cumsum[2][j]=N-j;
  for(int i=1;i>=0;i--){
    for(int j=N-1;j>=0;j--){
      int k=upper_bound(A[i+1].begin(),A[i+1].end(),A[i][j])-A[i+1].begin();
      cumsum[i][j]=cumsum[i][j+1]+cumsum[i+1][k];
    }
  }
  cout<<cumsum[0][0];
  return 0;
}