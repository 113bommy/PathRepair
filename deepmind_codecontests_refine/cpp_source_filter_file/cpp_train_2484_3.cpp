#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define RFOR(i,m,n) for(int i=m;i>=n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int n;
int a[1000000];
int x=0;

int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
    x = x^a[i];
  }

  int ans=0;
  for (int k=30; k>=1; k--) {
    if (x == 0) break;
    if (!(x>>(k-1) & 1)) continue;
 
    for (size_t i=0; i<N; ++i) {
      if ((a[i]^(a[i]-1)) == (1<<k)-1) {
        x ^= (1<<k)-1;
        ++res;
        a[i] = 0;  
        break;
      }
    }
  }


  if(x!=0){
    cout<<-1<<endl;
  }
  else{
    cout<<ans<<endl;
  }

  return 0;
}