#include <iostream>
#include <algorithm>

using namespace std;

inline int adj(int x) {
  return min(max(x, 0), 255);
}
#define SQ(x) ((x)*(x))
int main() {
  int N, M, INF=1<<28;
  while(cin >> N >> M && (N|M)) {
    int C[M];
    for(int i=0; i<M; i++) cin >> C[i];
    int dp[2][256]; fill(dp[0], dp[0]+512, INF);
    dp[0][128] = 0;
    for(int k=0; k<N; k++) {
      for(int i=0; i<256; i++) dp[(k+1)%2][i] = INF;
      int in; cin >> in;
      for(int i=0; i<256; i++) {
        if(dp[k%2][i]>=INF) continue;
        for(int j=0; j<M; j++) {
          dp[(k+1)%2][adj(i+C[j])] = min(dp[(k+1)%2][adj(i+C[j])], dp[k%2][i]+SQ(in-adj(i+C[j])));
        }
      }
    }
    cout << *min_element(dp[N%2], dp[(N%2)+1]) << endl;
  }
  
  return 0;
}