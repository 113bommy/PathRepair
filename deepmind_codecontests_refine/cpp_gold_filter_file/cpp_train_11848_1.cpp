#include <bits/stdc++.h>
using namespace std;

const int N = 100005;;
int n, a[N], b[N];
int main() {
  cin >> n;
  for(int i=0; i<=n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  
  int64_t ans = 0;
  for(int i=0; i<n; i++) {
  	ans += min(a[i],b[i]);
    b[i]=max(0,b[i]-a[i]);
    ans += min(a[i+1], b[i]);
    a[i+1]=max(0,a[i+1]-b[i]);
  }
  cout << ans << endl;
  return 0; 
}