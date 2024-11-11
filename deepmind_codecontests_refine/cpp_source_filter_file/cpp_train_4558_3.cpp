#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  long ans = 0;
  long u,v;
  rep(i,n-1){
    cin >> u >> v;
    if(u>v)swap(&u,&v);
    ans += (i+1)*(n-i) - u*(n-v+1);
  }
  ans += n;
  cout << ans << endl;
  return 0;
}