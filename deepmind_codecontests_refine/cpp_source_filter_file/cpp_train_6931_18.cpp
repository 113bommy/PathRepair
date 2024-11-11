#include <bits/stdc++.h>
using namespace std;
long long int prime[10000050];
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  prime[0] = prime[1] = 1;
  for (long long int i = 4; i <= 10000050; i += 2) prime[i] = 1;
  for (long long int i = 3; i * i <= 10000050; i += 2)
    if (!prime[i])
      for (long long int j = i * i; j <= 10000050; j += 2 * i) prime[j] = 1;
  long long int n;
  cin >> n;
  if (n == 1)
    cout << "1\n";
  else
    cout << "2\n";
  for (long long int i = 1; i <= n; ++i) {
    if (!prime[i + 1])
      cout << "1 ";
    else
      cout << "2 ";
  }
  return 0;
}
