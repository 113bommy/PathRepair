#include <bits/stdc++.h>
using namespace std;
using ll = long long:

int main(){
  ll n;
  cin >> n;
  for(ll i = sqrt(n); ; i--) if(n % i == 0){
    cout << i + n / i - 2 << endl;
    return 0;
  }
}