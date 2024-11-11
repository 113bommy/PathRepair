#include <bits/stdc++.h>
using namespace std;
int main() {
  long long modu = 1000000007;
  unsigned long long arr[100000];
  arr[0] = 1;
  arr[1] = 1;
  for (long long i = 2; i <= 100000; i++) {
    long long j = 2 * (i - 1);
    arr[i] = ((arr[i - 1] % modu) * ((j + 1) * (j + 2) % modu)) % modu;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << arr[n] << endl;
  }
  return 0;
}
