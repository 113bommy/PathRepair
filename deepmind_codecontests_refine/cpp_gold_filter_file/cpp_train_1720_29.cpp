#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n;
  cin >> n;
  unsigned long long int p = 0;
  unsigned long long int val = 0;
  while (val < n) {
    p++;
    val = (p * (p + 1)) / 2;
  }
  int diff = val - n;
  int ans = p - diff;
  cout << ans << endl;
}
