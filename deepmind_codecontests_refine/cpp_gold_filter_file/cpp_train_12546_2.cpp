#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sum = 0;
  int n;
  cin >> n;
  int smallest_odd = 1e9;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a % 2) {
      smallest_odd = min(smallest_odd, a);
    }
    sum += a;
  }
  if (sum % 2) sum -= smallest_odd;
  cout << sum << '\n';
}
