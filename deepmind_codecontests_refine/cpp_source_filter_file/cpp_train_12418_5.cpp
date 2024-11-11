#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n * k + 1, 0), brr(n * k + 1, 0);
  long long sum = 0;
  for (int i = 1; i <= n * k; i++) {
    cin >> v[i];
    brr[i] = v[i];
  }
  brr[0] = INT_MAX;
  sort(brr.rbegin(), brr.rend());
  if (n % 2 == 0) {
    int right = n / 2 + 1;
    int i = right;
    int j = 0;
    while (j < k) {
      sum = sum + brr[i];
      i = i + right;
      j++;
    }
  } else {
    int right = n / 2;
    int i = right;
    int j = 0;
    while (j < k) {
      sum = sum + brr[i];
      i = i + right;
      j++;
    }
  }
  cout << sum << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
