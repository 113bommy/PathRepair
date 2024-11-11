#include <bits/stdc++.h>
using namespace std;
int main() {
  int h;
  long long n;
  cin >> h >> n;
  n -= 1;
  long long r = 1 << h;
  int l = 0;
  long long mx = 0;
  while (r >>= 1) {
    if (((r & n) && 1) ^ l) mx += (r << 1) - 1;
    l = ((r & n) && 1) ^ 1;
  }
  cout << mx + h;
  return 0;
}
