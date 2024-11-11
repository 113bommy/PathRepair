#include <bits/stdc++.h>
using namespace std;
long long n;
long long modx = 1000003;
long long powx(int n, long long s) {
  if (n > 0) {
    return powx(n - 1, s) * 3 % modx;
  } else {
    return 1;
  }
}
int main() {
  cin >> n;
  cout << powx(n - 1, 1) % modx;
}
