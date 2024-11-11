#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  int incre = 1;
  for (int i = 3; i <= n; i++) {
    sum += incre;
    incre += 2;
  }
  cout << sum;
  return 0;
}
