#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
bool ascending(int i, int j) { return (i < j); }
bool descending(int i, int j) { return (i > j); }
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long t = 0, c = 1;
  for (int(i) = 0; (i) < (m); (i)++) {
    int a;
    cin >> a;
    if (a >= c)
      t += a - c;
    else
      t += n - c + a;
    c = a;
  }
  cout << t << endl;
}
