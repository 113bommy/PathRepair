#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, a, b, c = 0;
  cin >> n >> a;
  for (int i = 1; i <= n; i++) {
    if (i * n >= a && a % i == 0) c++;
  }
  cout << c;
}
