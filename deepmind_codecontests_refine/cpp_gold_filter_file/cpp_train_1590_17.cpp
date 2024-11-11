#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long int a = 1e10;
  long long int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int c = 1;
  sort(v, v + n);
  long long int cost = 1e14, prev_cost = 1e14;
  for (long long int x = 1; x <= 1e10; x++) {
    long long int temp_cost = 0;
    double prod = 1;
    for (int i = 0; i < n; i++) {
      temp_cost += abs(v[i] - prod);
      if (prod >= 1e14) break;
      prod *= x;
    }
    if (temp_cost > prev_cost) {
      cout << prev_cost;
      return 0;
    }
    prev_cost = temp_cost;
  }
}
