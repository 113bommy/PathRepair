#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  int arr[n + 1];
  memset(arr, 0, sizeof(arr));
  while (m--) {
    long long mv = 0, w;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x > mv) {
        mv = x;
        w = i + 1;
      }
    }
    arr[w] = arr[w] + 1;
  }
  long long mc = 0, winner;
  for (long long i = 0; i < n + 1; i++) {
    if (arr[i] > mc) {
      mc = arr[i];
      winner = i;
    }
  }
  cout << winner << "\n";
  return 0;
}
