#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  long k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
 
  int inner = 0;
  int outer = 0;
 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
    	if( a[i] <= a[j]) {
				continue;
			}
		
     	 outer++;
			if( j >= i ){
				inner++;
			}
    }
  }
  long mod = 1000000007;
 long ans = k * (k - 1) / 2 % mod;
	ans = (ans*outer + k*inner) % mod;
  cout << ans << endl;
  return 0;
}
