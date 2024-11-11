#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

  ll N;
  cin >> N;

  ll sum = 0;

  for(ll i=1; i*i<=N; i++){
    if(n%i != 0) continue;
    ll t = n/i;
    t--;
    if(i<t) sum+=t;
  }

  cout << sum;

  return 0;
}
