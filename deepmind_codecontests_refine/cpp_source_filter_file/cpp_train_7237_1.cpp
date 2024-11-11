#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  int total = a + 1;
  int q = 1;
  if (b % 2)
    cout << (b - 1) / 2 + q;
  else {
    cout << (total - a) / 2 + q;
  }
}
