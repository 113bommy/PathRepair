#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b) { return b < a; }
int main() {
  long long i;
  long long N;
  cin >> N;
  long long arr[N];
  long long freq[1000000] = {0};
  long long maxfre = 0;
  long long num = 0;
  for (i = 0; i < N; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
    if (freq[arr[i]] > maxfre) {
      maxfre = freq[arr[i]];
      num = arr[i];
    }
  }
  long long start = 0;
  while (arr[start] != num) {
    start++;
  }
  cout << N - maxfre << endl;
  for (i = start; i > 0; i--) {
    if (arr[i] > arr[i - 1]) {
      cout << "1 " << i << " " << i + 1 << endl;
    } else if (arr[i] == arr[i - 1]) {
      int poop;
    } else {
      cout << "2 " << i << " " << i + 1 << endl;
    }
    arr[i - 1] = arr[i];
  }
  for (i = start + 1; i < N; i++) {
    if (arr[i] > arr[i - 1]) {
      cout << "2 " << i + 1 << " " << i << endl;
    } else if (arr[i] == arr[i - 1]) {
      int poop;
    } else {
      cout << "1 " << i + 1 << " " << i << endl;
    }
    arr[i - 1] = arr[i];
  }
  return 0;
}
