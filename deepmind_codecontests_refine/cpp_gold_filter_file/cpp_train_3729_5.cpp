#include <cstdio> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
int n,m;
int p[100000],y[100000]; vector<ll> yd[100001];
int main(){
  scanf("%d%d",&n,&m);
  rep(i,m){
    scanf("%d%d",&p[i],&y[i]);
    yd[p[i]].push_back(y[i]);
  }
  rep(i,n){
    sort(ALL(yd[i+1]));
  }
  rep(i,m){
    printf("%012lld\n",ll(p[i])*1000000+int(lower_bound(ALL(yd[p[i]]),y[i])-yd[p[i]].begin())+1);
  }
}
