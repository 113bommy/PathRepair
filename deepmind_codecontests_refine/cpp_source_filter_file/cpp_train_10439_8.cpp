#include <bits/stdc++.h>
using namespace std;
long long inputs[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long odd = 0;
  long long even = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> inputs[i];
    sum += inputs[i];
    if (i % 2 == 0)
      even += inputs[i];
    else
      odd += inputs[i];
  }
  long long ans = 0;
  if (n % 3 == 1) ans = sum;
  sort(inputs, inputs + n);
  for (int i = 0; i < n; i++) {
    sum -= 2 * inputs[i];
    if ((n + i + 1) % 3 == 1) {
      if (sum == even - odd || sum == odd - even)
        ans = max(ans, sum + 2 * inputs[i] - 2 * inputs[i + 1]);
      else
        ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}
