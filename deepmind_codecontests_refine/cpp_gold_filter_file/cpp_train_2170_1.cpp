#include <bits/stdc++.h>
using namespace std;typedef long long ll;
int main(){
  ll n, a, x = 1;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 0) {
      x *= 2;
    }
  }
  cout << pow(3, n) - x << endl;
}