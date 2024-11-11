#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

  ll N;
  cin >> N;

  ll sum = 0;

  for(ll i=1; i*i<=N; i++){
    if(N%i != 0) continue;
    ll t = N/i;
    t--;
    if(i<t) sum+=t;
  }

  cout << sum;

  return 0;
}
