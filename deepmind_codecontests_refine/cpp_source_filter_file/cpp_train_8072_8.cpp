#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  cin >> n;
  int a[n], sm = 0;
  for (unsigned long long i = 0; i < (unsigned long long)n; i++) {
    cin >> a[i];
    sm += a[i];
  }
  int i = 0, j = n - 1, left = 0, right = 0;
  while (i + 1 < j) {
    if (left <= right) {
      left += a[i];
      i++;
    }
    if (right < left) {
      right += a[j];
      j--;
    }
  }
  cout << i << " " << n - i;
  return 0;
}
