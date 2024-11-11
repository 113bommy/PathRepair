#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL<<60;
int main() {
  int H,N; cin>>H>>N;
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N) cin>>A.at(i)>>B.at(i);
  vector<long long> dp(H+1, INF);
  DP[0]=0;
  for(int i=0;i<=H;i++){
    rep(j,N){
      DP[min(i+A.at(j),H)]=min(DP[min(i+A.at(j),H)],DP[i]+B.at(j));
    }
  }
  cout<<DP[H];
}