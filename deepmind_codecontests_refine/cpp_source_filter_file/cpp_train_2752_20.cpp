#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p = 0, non = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < 0 && p <= 0) non++;
    if (x > 0) p++;
    if (x < 0 && p > 0) p--;
  }
  cout << non;
  return 0;
}
