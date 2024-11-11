#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n, m;
  cin >> n >> m;
  int a, b, t;
  cin >> a;
  for (int(i) = 0; (i) < (n); (i)++) cin >> t;
  cin >> b;
  if (n < m) {
    puts("0/1");
  } else if (n > m) {
    if (a * b < 0)
      puts("-Infinity");
    else
      puts("Infinity");
  } else {
    int g = gcd(abs(a), abs(b));
    if (a * b < 0) {
      cout << "-";
    }
    cout << abs(a) / g << "/" << abs(b) / g << endl;
  }
  return 0;
}
