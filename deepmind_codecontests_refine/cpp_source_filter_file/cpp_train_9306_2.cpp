#include <bits/stdc++.h>
using namespace std;
int countPairs(int a[], int n, int d) {
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((abs(a[i] - a[j])) <= d) count += 2;
    }
  }
  return count;
}
int main() {
  int a[101], n, d;
  std::cin >> n >> d;
  for (int i = 1; i < n; i++) {
    std::cin >> a[i];
  }
  std::cout << countPairs(a, n, d);
  return 0;
}
