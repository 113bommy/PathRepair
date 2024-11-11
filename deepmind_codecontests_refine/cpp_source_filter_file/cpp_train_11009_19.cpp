#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sol = 0;
  cin >> n;
  if (n >= 100) {
    int times = n / 100;
    n -= times * 100;
    sol = times;
  }
  if (n >= 20) {
    int times = n / 20;
    n -= times * 20;
    sol = times;
  }
  if (n >= 10) {
    int times = n / 10;
    n -= times * 10;
    sol = times;
  }
  if (n >= 5) {
    int times = n / 5;
    n -= times * 5;
    sol = times;
  }
  if (n >= 1) {
    int times = n / 1;
    n -= times * 1;
    sol = times;
  }
  cout << sol;
}
