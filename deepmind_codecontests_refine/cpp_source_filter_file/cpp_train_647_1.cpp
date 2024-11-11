#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N;
  cin >> N;
  long long int arr[N];
  for (long long int i = 0; i < N; i++) cin >> arr[i];
  long long int lsum = 0, gsum = 0;
  for (long long int j = 30; j >= 1; j--) {
    lsum = 0;
    for (long long int i = 0; i < N; i++) {
      if (arr[i] > i) {
        lsum = 0;
        continue;
      }
      lsum = max((long long int)(0), lsum + arr[i]);
      gsum = max(gsum, lsum - j);
    }
  }
  cout << gsum << endl;
  return 0;
}
