#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  int max = 0;
  int maxin = 0;
  int sum;
  int sizes[int(1e3)];
  int sums[int(2 * 1e5)] = {};
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> sizes[i];
    if (sizes[i] > maxin) {
      maxin = sizes[i];
    }
  }
  for (int i = 0; i < num; i++) {
    for (int j = i + 1; j < num; j++) {
      sum = sizes[i] + sizes[j];
      sums[sum] += 1;
    }
  }
  for (int i = 0; i < 2 * maxin; i++) {
    if (sums[i] > max) {
      max = sums[i];
    }
  }
  cout << (max);
}
