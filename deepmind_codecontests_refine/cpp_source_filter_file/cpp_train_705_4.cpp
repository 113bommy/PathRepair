#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> v(n);
  for(int i=0;i<m;i++){
    int k;
    cin >> k;
    for(int j=0;j<k;j++){
      int s;
      cin >> s;
      s--;
      v[s] |= (1<<i);
    }
  }
  int p=0;
  int ans =0;
  for(int i=0;i<m;i++){
    int x;
    cin >> x;
    p |= (x<<i);
  }
  
  for(int bit; bit<(1<<n);i++){
    int t=0;
    for(int i=0;i<n;i++){
      if(bit>>i&1) {
        t ^= v[i];
      }
    }
    if(t==p) ans++;
  }
  cout << ans << endl;
}
