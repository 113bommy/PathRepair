#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, minoperations;
  long long sum;
  map<long long, int> parts;
  sum = 0;
  cin >> n;
  minoperations = n - 1;
  for (int a = 0; a < n; ++a) {
    parts[a] = 0;
  }
  for (int a = 0; a < n; ++a) {
    int k;
    cin >> k;
    sum += k;
    ++parts[sum];
    minoperations = min(minoperations, n - parts[sum]);
  }
  cout << minoperations << endl;
  return 0;
}
