#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef int number;
typedef vector<number> Array;
typedef vector<Array> matrix;

const int mod = 1000000009;

// O( n )
matrix identity(int n) {
  matrix A(n, Array(n));
  for (int i = 0; i < n; ++i) A[i][i] = 1;
  return A;
}
// O( n^2 )
Array mul(const matrix &A, const Array &x) {
  Array y(A.size());
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < A[0].size(); ++j)
      y[i] = (y[i] + A[i][j] * x[j]) % mod;
  return y;
}
// O( n^3 )
matrix mul(const matrix &A, const matrix &B) {
  matrix C(A.size(), Array(B[0].size()));
  for (int i = 0; i < C.size(); ++i)
    for (int j = 0; j < C[i].size(); ++j)
      for (int k = 0; k < A[i].size(); ++k)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
  return C;
}
// O( n^3 log e )
matrix pow(const matrix &A, int e) {
  return e == 0 ? identity(A.size())  :
     e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}

#define range(i,x,y) i=(x);i<(y);i++
#define rep(i,n) for(int i=0,i##_len=n;i<i##_len;i++)
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;


signed main(){
  int w, h, n; int num = 1;
  while(cin >> w >> h >> n, w != 0){
  map<int, vector<int>> obst;
  rep(i, n){
    int x, y; cin >> x >> y;
    if (obst.find(y) == obst.end()){
      obst[y] = vector<int>{x};
    } else {
      obst[y].push_back(x);
    }
  }
  if (obst.find(h) == obst.end()){
    obst[h] = vector<int>{1};
  }
  Array res(w);
  res[0] = 1;

  matrix way(w, Array(w));
  rep(i, w){
    if(i-1 >= 0) way[i][i-1] = 1;
                  way[i][i] = 1;
    if(i+1 <  w) way[i][i+1] = 1;
  }

  int prv = 1;
  for(auto ob : obst){
    int y; vector<int> xs; tie(y, xs) = ob;
    res = mul(pow(way, y - prv), res);
    for(int x: xs){
      r2es[x - 1] = 0;
    }
    prv = y;

  }
  cout << "Case " << num << ": " << res[w-1] << endl;
  num++;
  }
}