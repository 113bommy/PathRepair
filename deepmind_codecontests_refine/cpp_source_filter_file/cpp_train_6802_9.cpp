#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 1e18;
long long int s, a, b, c;
double x, y, z;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> s >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    cout << s - 2 << " " << 1 << " " << 1 << endl;
  } else {
    x = (double)(a * s) / (double)(a + b + c);
    y = (double)(b * s) / (double)(a + b + c);
    z = (double)(c * s) / (double)(a + b + c);
    printf("%0.15f %0.15f %0.15f", x, y, z);
  }
}
