#include <bits/stdc++.h>
using namespace std

int main(){
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> ans(N-1);
  int tmp;
  for  (int i = 1; i < N+1; i++){
    for (int j = i+1; j < N+1; j ++){
      tmp = min(j-i, abs(X-i) +1 + abs(Y-j));
      ans.at(tmp-1) += 1;
    }
  }
  for (int k = 0; k < N-1; k++){
    cout << ans.at(k) << endl;
  }
}
