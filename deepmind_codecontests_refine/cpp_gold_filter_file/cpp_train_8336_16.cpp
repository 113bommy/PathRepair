#include <bits/stdc++.h>
using namespace std;
int main() {
  clock_t tStart = clock();
  std::vector<long long> v;
  long long start = 2;
  while (start <= 3 * 1e9) {
    v.push_back(start);
    start *= 2;
  }
  long long n;
  scanf("%lld", &n);
  std::vector<long long> arr;
  for (long long i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());
  bool check[n];
  for (long long i = 0; i < n; i++) {
    check[i] = 0;
  }
  for (long long i = 0; i < n; i++) {
    if (check[i] == false) {
      for (long long j = 0; j < v.size(); j++) {
        long long temp = v[j] - arr[i];
        bool f = 0;
        if (temp >= 1) {
          auto p1 = lower_bound(arr.begin(), arr.end(), temp);
          if (p1 != arr.end()) {
            long long ind = p1 - arr.begin();
            if (arr[ind] == temp) {
              if (ind != i) {
                f = 1;
                check[ind] = 1;
                check[i] = 1;
              } else {
                if (ind + 1 < arr.size() && arr[ind + 1] == arr[i]) {
                  f = 1;
                  check[ind] = 1;
                  long long start = ind + 1;
                  long long blah = start;
                  while (start + 1 < arr.size() && arr[start + 1] == arr[i])
                    start++;
                  for (long long k = blah; k <= start; k++) {
                    check[k] = 1;
                  }
                }
              }
            }
          }
        }
        if (f) break;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!check[i]) ans++;
  }
  printf("%lld\n", ans);
  return 0;
}
