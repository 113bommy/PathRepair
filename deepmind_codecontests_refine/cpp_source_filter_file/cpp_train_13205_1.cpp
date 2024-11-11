#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

LL comb(LL n, LL k){
  LL r=1;
  for(LL d=1; d<=k; d++){
    r*=n;
    n--;
    r/=d;
  }
  return r;
}

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<double> v(N);
  rep(i,N) cin >> v[i];
  sort(v.begin(),v.end(),greater<double>());
  double sum=0;
  rep(i,A) sum+=v[i];
  double ans=sum/A;
  LL num=0, n=0;
  rep(i,N) if(v[i]==v[0]) n++;
  if(n>=A) for(LL k=A; k<=min(n,B); k++) num+=comb(n,k);
  else{
    n=0;
    rep(i,N) if(v[i]==v[A-1]) n++;
    LL k=0;
    rep(i,A) if(v[i]==v[A-1]) k++;
    num+=comb(n,k);
  }
  cout << fixed <<  setprecision(15) << ans << endl;
  cout << num << endl;

  return 0;
}
