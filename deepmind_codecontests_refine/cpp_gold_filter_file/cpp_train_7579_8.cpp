#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, k, mn = 1e+9;
  cin >> n >> k;
  int h[n];
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  sort(h, h+n, greater<int>());
  for(int i=0;i<=n-k;i++){
    mn = min(mn,h[i]-h[i+k-1]);
  }
  cout << mn << endl;
}