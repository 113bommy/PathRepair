#include <bits/stdc++.h>
using namespace std;
int main() {
  clock_t tStart = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long center = 1;
  long long mx = INT_MIN;
  if (m == 0) {
    goto lbl;
  }
  long long arr[1001];
  memset(arr, 0, sizeof(arr));
  for (long long i = 0; i < m; i++) {
    long long n1, n2;
    cin >> n1 >> n2;
    mx = max(mx, max(n1, n2));
    arr[n1]++;
    arr[n2]++;
  }
  for (long long i = 1; i < mx + 1; i++) {
    if (arr[i] == 0) {
      center = i;
      break;
    }
  }
lbl:
  cout << n - 1;
  cout << "\n";
  for (long long i = 1; i < n + 1; i++) {
    if (i != center) {
      cout << i << " " << center;
      cout << "\n";
    }
  }
  return 0;
}
