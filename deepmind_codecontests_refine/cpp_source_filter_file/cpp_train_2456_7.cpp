#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  long long int n, k, sum = 0;
  std::cin >> n >> k;
  long long int ar[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> ar[i];
  }
  sort(ar, ar + n);
  for (int i = 0; i < n - 1; ++i) {
    if (ar[i + 1] - ar[0] < k) {
      std::cout << -1;
      exit(0);
    } else
      sum += (ar[i + 1] - ar[0]) / k;
  }
  std::cout << sum << "\n";
  return 0;
}
