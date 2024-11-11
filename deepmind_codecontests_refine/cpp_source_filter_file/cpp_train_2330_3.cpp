#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T x) {
  cout << x << "\n";
}
template <typename T1, typename T2>
void print2(T1 x, T2 y) {
  cout << x << " " << y << "\n";
}
template <typename T1, typename T2, typename T3>
void print3(T1 x, T2 y, T3 z) {
  cout << x << " " << y << " " << z << "\n";
}
long long arr[100000 + 1], s[100000 + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long test_case;
  test_case = 1;
  while (test_case--) {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) cin >> arr[i], s[i] = s[i - 1] + arr[i];
    long long l, r, ans = 0;
    for (int i = 1; i < n; i++) {
      if (arr[i] > k) continue;
      l = i, r = n;
      while (l < r) {
        int mid = (l + r) / 2;
        mid++;
        if (s[mid] - s[i - 1] <= k)
          l = mid;
        else
          r = mid - 1;
      }
      ans = max(ans, l - i + 1);
    }
    print(ans);
  }
}
