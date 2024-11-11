#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxx = 0;
  cin >> n;
  int a, b, sum = 0;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    sum += b - a;
    maxx = max(maxx, sum);
  }
  cout << maxx << endl;
  return 0;
}
