#include <bits/stdc++.h>
using namespace std;

typedef long long ll

int main(){
  ll a,b;
  cin >> a >> b;
  
  int ret = 1;
  for(ll i = 2;i*i <= min(a,b);i++){
    if(a%i == 0 && b%i == 0)ret++;
    while(a%i == 0)a /= i;
    while(b%i == 0)b /= i;
  }
  if(a > 1 && b > 1){
  	if(b % a == 0 || a % b == 0)ret++;
  }
  
  cout << ret << endl;
}