#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pi;
  unsigned long long sum = 0;
  double ratio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> pi;
    sum += pi;
  }
  ratio = sum;
  cout << ratio / n << '\n';
};
