#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

const int INF=1e9;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin>>N;
  int M=3*N;
  vector<int> A(M);
  rep(i,M) cin>>A[i];

  rep(i,M) A[i]--;
  vector<vector<int>> dp(N,vector<int> (N,-INF));
  dp[A[0]][A[1]]=0;
  dp[A[1]][A[0]]=0;
  int all=0;

  vector<int> mva(N,-INF);
  mva[A[0]]=0;
  mva[A[1]]=0;
  for(int k=1;k<N;k++){
    int now=3*k-1;
    if(A[now]==A[now+1]&&A[now+1]==A[now+2]){
      all++;
      continue;
    }

    vector<int> nexmva=mva;
    if(A[now]==A[now+2]) swap(A[now+1],A[now+2]);
    if(A[now+1]==A[now+2]) swap(A[now],A[now+2]);

    if(A[now]==A[now+1]){
      int tar=A[now];
      int val=dp[A[now+2]][A[now+2]];
      vector<int> pp=dp[tar];
      for(int j=0;j<N;j++){
        int V=pp[j];
        if(V!=-INF){
            chmax(dp[j][A[now+2]],V+1);
            chmax(dp[A[now+2]][j],V+1);
            chmax(nexmva[j],V+1);
            chmax(nexmva[A[now+2]],V+1);
        }
      }
      if(val!=-INF){
        chmax(dp[tar][tar],val+1);
        chmax(nexmva[tar],val+1);
      }
    }else{
      for(int l=0;l<=2;l++){
          int V=dp[A[now+l]][A[now+l]];
          if(V==-INF) continue;
          int fir=now+(l+1)%3;
          int sec=now+(l+2)%3;
          chmax(dp[A[fir]][A[sec]],V+1);
          chmax(dp[A[sec]][A[fir]],V+1);
          chmax(nexmva[A[fir]],V+1);
          chmax(nexmva[A[sec]],V+1);  
      }
    }

    for(int j=now;j<=now+2;j++){
        for(int m=0;m<N;m++){
            chmax(dp[A[j]][m],mva[m]);
            chmax(dp[m][A[j]],mva[m]);
            chmax(nexmva[A[j]],mva[m]);
        }
    }

    int ma=*max_element(all(mva));
    for(int j=now;j<=now+2;j++) for(int m=now;m<j;m++){
        chmax(dp[A[j]][A[m]],ma);
        chmax(dp[A[m]][A[j]],ma);
        chmax(nexmva[A[j]],ma);
        chmax(nexmva[A[m]],ma);
    }
    mva=nexmva;
  }

  int ans=0;
  for(int i=0;i<N;i++) for(int j=0;j<N;j++){
    if(dp[i][j]==-INF) continue;
    int last=0;
    if(i==j&&i==A.back()) last=1;
    chmax(ans,dp[i][j]+last);
  }
  ans+=all;
  cout<<ans<<endl;

  return 0;
}
