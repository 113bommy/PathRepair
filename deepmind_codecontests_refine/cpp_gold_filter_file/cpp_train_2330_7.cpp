#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t;
  cin >> n >> t;
  long long int A[n];
  for (long long int i = 0; i < n; i++) {
    cin >> A[i];
  }
  long long int cnt = 0;
  long long int sum = 0;
  long long int i = 0;
  long long int j = 0;
  for (i = 0; i < n; i++) {
    sum += A[i];
    while (sum > t) {
      sum -= A[j];
      j++;
    }
    cnt = max(cnt, i - j + 1);
  }
  cout << cnt << endl;
}
