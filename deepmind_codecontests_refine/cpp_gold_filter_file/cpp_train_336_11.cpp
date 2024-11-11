#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a = 1, b = 1;
  for (int i = 1; i <= (int)(n); ++i) a = (a * i) % 1000000007;
  for (int i = 1; i <= (int)(n - 1); ++i) b = (b * 2) % 1000000007;
  cout << (a - b + 1000000007) % 1000000007;
  return 0;
}
