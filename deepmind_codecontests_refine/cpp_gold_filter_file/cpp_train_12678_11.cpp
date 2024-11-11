#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << n/(a+b)*a + min(n%(a+b), a);
}