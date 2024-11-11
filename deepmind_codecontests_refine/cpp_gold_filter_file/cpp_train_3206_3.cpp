#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long a, b, k; cin >> a >> b >> k;
  long long tmp = min(a, k);
  a -= tmp; k-= tmp; b -= min(b, k);
  cout << a << " " << b << endl;
}