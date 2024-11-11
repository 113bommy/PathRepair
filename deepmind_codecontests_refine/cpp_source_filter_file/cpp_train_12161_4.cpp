#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,C;
  cin >> N >> M >> C;
  int sum=0;
  int B[M],A[M];
  for(int i=0;i<M;i++){
    cin >> B[i];
  }
  for(int i=0;i<N;i++){
    int bab=0;
    for(int j=0;j<M;j++){
      cin >> A[i];
      bab+=A[i]*B[i]
    }
    bab+=C;
    if(bab>0)sum+=1;
  }
  cout << sum <<endl;
}