#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000
#define N_MAX 5000
#define M_MAX 500000

int nails[N_MAX+2][N_MAX+2];

int main(){
  int n,m;
  cin >> n >> m;

  rep(i, n+2){
    rep(j,i+2)
      nails[i][j]=0;
  }

  // imosu method (applying to triangle)
  int a,b,x;
  rep(i, m){
    scanf("%d %d %d", &a, &b, &x);
    a--; b--;
    nails[a][b]++;
    nails[a][b+1]--;
    nails[a+x+1][b]--;
    nails[a+x+2][b+1]++;
    nails[a+x+2][b+x+2]--;
    nails[a+x+1][b+x+2]++;
  }

  int current=0;
  // from left to right
  rep(i, n){
    current=0;
    rep(j, i+1){
      current += nails[i][j];
      nails[i][j] = current;
    }
  }
  // from upper-right to bottom-left
  rep(i,n){
    current=0;
    rep(j,n-i){
      current += nails[i+j][i];???
      nails[i+j][i] = current;
    }
  }

  int res=0;
  // from upper-left to bottom-right
  rep(i,n){
    current=0;
    rep(j, n-i){
      current += nails[i+j][j];
      nails[i+j][j] = current;
      if(current>0) res++;
    }
  }

  /*
  rep(i, n){
    rep(j,i+1){
      cout << nails[i][j];
    }
    cout << endl;
  }
  */


  cout << res << endl;

}