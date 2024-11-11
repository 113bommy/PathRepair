include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 1001001001;
using namespace std;

int main()
{
  int N, M;
  int a[51], b[51], c[51], d[51];
  int res[51];
  cin >> N >> M;

  rep(i,N) cin >> a[i] >> b[i];
  rep(i,M) cin >> c[i] >> d[i];

  rep(i,N){
    int minmd = INF;
    rep(j,M){
      int md = abs(a[i]-c[j])+abs(b[i]-d[j]);
      if(minmd > md) {
        res[i]=j+1;
        minmd = md;
      }
    }
  }

  rep(i,N){
    cout << res[i] << endl;
  }
}
