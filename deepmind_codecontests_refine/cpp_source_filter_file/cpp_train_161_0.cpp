#include <bits/stdc++.h>
using namespace std;
int n;
char p[] = {"1000101021120100"};
int main() {
  cin >> n;
  if (!n) {
    puts("1");
    return 0;
  }
  int q = 0;
  while (n) q += p[n % 2] - 48, n /= 2;
  cout << q << "\n";
}
