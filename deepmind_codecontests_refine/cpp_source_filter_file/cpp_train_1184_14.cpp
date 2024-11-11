#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long n, k;
  cin >> n >> k;
  n--;
  k--;
  long long sum = k * (k + 1) / 2;
  if (sum < n) {
    cout << "-1";
  } else if (n == 1) {
    cout << "0";
  } else {
    long long answer = -1;
    long long L = 1;
    long long R = k;
    long long x = 0;
    while (L <= R) {
      long long mid = L + (R - L) / 2;
      sum = ((k - mid + 1) * (k + mid)) / 2;
      if (sum >= n) {
        answer = k - mid + 1;
        L = mid + 1;
        x = sum;
      } else {
        R = mid - 1;
      }
    }
    if (n > x) {
      answer++;
    }
    cout << answer;
  }
}
