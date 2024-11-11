#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)
#define rev(i, n) for(int i=(n)-1; i>=0; i--)

int n;
int d[111];
int r[111];
int A, B, C, D;

int main(int argc, char *argv[])
{
  cin >> n;
  rep(_, n * (n - 1) / 2){
    cin >> A >> B >> C >> D;
    if(C > D){
      d[A - 1] += 3;
    }
    else if(C < D){
      d[B - 1] += 3;
    }
    else{
      d[A - 1] += 1;
      d[B - 1] += 1;
    }
  }

  vector<int> res[333];
  rep(i, 333) rep(j, n) if(d[j] == i) res[i].push_back(j);

  int p = 1;
  rev(i, 333) if(res[i].size()){
    rep(j, res[i].size()) r[res[i][j]] = p;
    p += res[i].size();
  }

  rep(i, n) cout << r[i] << endl;
  
  return 0;
}