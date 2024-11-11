#include <bits/stdc++.h>
using namespace std;
const int N = 100011;
long long a[N];
int main() {
  ios ::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long left = *max_element(a, a + n);
  long long right = left * 2 + 1;
  long long sum = accumulate(a, a + n, 0LL);
  while (left + 1 < right) {
    long long mid = (left + right) / 2;
    if (n * (mid - 1) - sum >= mid - 1)
      right = mid;
    else
      left = mid;
  }
  cout << left << '\n';
  return 0;
}
