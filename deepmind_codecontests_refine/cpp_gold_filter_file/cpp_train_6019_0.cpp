#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int last,x,n,c[200019];
ll ans;

int main() {
  cin >> n;
  ans=1;
  last=-1;

  for(int i=0; i<n; i++){c[i]=0;}
  
  for(int i=0; i<n; i++){
    cin >> x;
    if(x==last){continue;}
    last=x;
    ans = (ans+c[x])%1000000007;
    c[x]=ans;
  }

  cout << ans << endl;
  return 0;
}