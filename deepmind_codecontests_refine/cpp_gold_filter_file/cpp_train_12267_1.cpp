#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n, k, s;
  long long ans = 0;
  cin >> n >> k;
  
  for(int i = k+1; i <= n; i++){
    if(k){
      if(n%i-k>=0) s = n%i-k+1;
      else s = 0;
    }else s = n%i;
    ans += n/i*(i-k) + s;
  }
  cout << ans << endl;
}
