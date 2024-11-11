#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, o;
  cin >> n >> k;
  if (n * 2 == k) {
    cout << n;
    exit(0);
  }
  if (k >= n * 3) {
    cout << 0;
    exit(0);
  }
  o = k / 3 + (k % 3) / 2 + (k % 3) % 2;
  cout << (k % 3) / 2 + (k % 3) % 2 + (n - o) * 3;
}
