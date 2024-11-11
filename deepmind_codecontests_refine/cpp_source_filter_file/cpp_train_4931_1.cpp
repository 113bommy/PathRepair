#include <bits/stdc++.h>
using namespace std;
double prob[100000];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> prob[i];
  }
  double total = 0;
  double prev = 0;
  for (int i = 0; i < n; i++) {
    total += prev * prob[i] * 2 + prob[i];
    prev = prev * prob[i] + prob[i];
  }
  cout << setprecision(6) << total;
}
