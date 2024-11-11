#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,l,i,p,ans=0;
  cin >> n >> l;
  if (l>=0) p=0;
  else if (-l<=n-1) p=-l;
  else p=n-1;
  for (i=0;i<n;i++) if (i!=p) ans+=l+i;
  cout << ans << endl;
  return 0;
}