#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X, Y; cin >> N >> X >> Y;
  vector<int> ans(N);
  ans[0]=0;
  for(int i=1;i<N){
    for(int j=i+1;j<=N;j++){
      int k=min(j-i,abs(X-i)+1+abs(Y-j));
      ans[k]++;
    }
  }
  for(int i=1;i<=N-1;i++){
    cout << ans[i] << endl;
  }
  return 0;
}
  
  
  