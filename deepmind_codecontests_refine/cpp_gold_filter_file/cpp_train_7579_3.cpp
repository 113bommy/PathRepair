#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  long int h[100002];
  long int ans=1000000001;
  cin >> n >> k;
  for(int i=0;i!=n;i++){
    cin >> h[i];
  }
  sort(h,h+n);
  for(int i=0;i!=n-k+1;i++){
    ans=min(ans,h[i+k-1]-h[i]);
  }
  cout << ans << endl;
}
