#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  for (long long i = 1; i <= (n * n) / 2; i++) {
    cout << i << " " << (n * n) - (i - 1) << "\n";
  }
  return 0;
}
