#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x = pow(4l, n - 2) * 6l;
  if (n > 3l) {
    x += pow(4l, n - 3l) * (n - 4l) * 9l;
  }
  cout << (x) << endl;
};
