#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
  cin >> n;
  for(int long long int i = 2; i <= sqrt(n); i++){
    long long x = i;
    while(n % x == 0){
      n = n/x;
      x = x*i;
      ans++;
    }
    while(n%i == 0) n = n/i;
  }
  if(n != 1) ans++;
  cout << ans << endl;
}