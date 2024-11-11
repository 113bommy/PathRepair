#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, K;
  cin >> N >> K;
  int h[N];
  for(int i=0; i<N; i++) cin >> h[i];
  sort(h, h+N);
  int ans=1e9;
  for(int i=0; i<=N-K; i++){
    ans = min(h[i+K-1]-h[i], ans);
  }
  cout << ans << endl;
  return 0;
}
