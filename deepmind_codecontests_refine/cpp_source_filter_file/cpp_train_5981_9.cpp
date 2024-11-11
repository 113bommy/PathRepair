#include <bits/stdc++.h>
using namespace std;
long long a[50010];
int main() {
  long long n;
  long long sum = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long t = 0;
  long long aver = sum / n;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans += labs(t);
    t += a[i] - aver;
  }
  cout << ans << endl;
  return 0;
}
