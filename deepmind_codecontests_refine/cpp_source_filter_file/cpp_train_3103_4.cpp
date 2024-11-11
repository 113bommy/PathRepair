#include<iostream>
using namespace std;
int main(){
  int a[101], n, t, ans = 100*100;
  a[0] = 0;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> t; 
    a[i] = a[i-1] + t;
  }
  int toatal = a[n];
  for(int i=1; i<=n; i++){
    ans = min(ans, abs(total - 2*a[i]));
  }
  cout << ans << endl;
  return 0;
}