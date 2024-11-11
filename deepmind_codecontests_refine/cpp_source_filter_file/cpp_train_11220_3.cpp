#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  __int128 t = A[0];
  for(int i = 1; i < N; i++){
    if(__int128)1e18 < t*A[i]){
      cout << -1 << endl;
      return 0;
    }
    t *= A[i];
  }
  long long ans = t;
  cout << ans << endl;
}