#include<iostream>
using namespace std;
int main(){
  int n,i,ans;cin >> n;ans = 0;
  int a[n];
  for(i=0;i<n;i++) cin >> a[i];
  for(i=0;i<n;i++){
    if (a[a[i]-1]-1 == i) ans += 1;
  }
  cout << ans/2 << endl;
}
