#include <cstdio> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
int N,M;
int P[100000],Y[100000]; vector<int> yd[100001];
int main () {

  scanf("%d%d",&N,&M);
  rep(i,M){
    scanf("%d%d",&P[i],&Y[i]);
    yd[P[i]].push_back(Y[i]);
  }
  rep(i,N){
    sort(ALL(yd[i+1]));
  }
  rep(i,M){
    printf("%012lld\n",ll(P[i])*1000000+int(lower_bound(ALL(yd[P[i]]),Y[i])-yd[P[i]].begin())+1);
  }
}