#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long N;
  cin >> N;
  long long count[200005] = {0};
  long long A[N];
  for (long long n = 0; n < N; n++) {
    cin >> A[n];
    count[A[n]]++;
  }
  long long max_freq = 0;
  long long max_freq_num;
  for (long long n = 0; n < 200005; n++) {
    if (count[n] > max_freq) {
      max_freq = count[n];
      max_freq_num = n;
    }
  }
  cout << N - max_freq << endl;
  long long index = -1;
  for (long long n = 0; n < N; n++) {
    if (A[n] == max_freq_num) {
      index = n;
      break;
    }
  }
  long long zero = 0;
  for (long long n = max(zero, index - 1); n >= 0; n--) {
    if (A[n] != max_freq_num) {
      long long code = (A[n] > max_freq_num) ? 2 : 1;
      if (code == 1)
        cout << code << " " << n + 1 << " " << n + 2 << endl;
      else
        cout << code << " " << n + 1 << " " << n + 2 << endl;
    }
  }
  for (long long n = min(index + 1, N - 1); n < N; n++) {
    if (A[n] != max_freq_num) {
      long long code = (A[n] > max_freq_num) ? 2 : 1;
      if (code == 1)
        cout << code << " " << n + 1 << " " << n << endl;
      else
        cout << code << " " << n + 1 << " " << n << endl;
    }
  }
  return 0;
}
