#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[200009];
int main() {
  long long a, x, ans = 0;
  cin >> a;
  for (int i = 1; i <= a; i++) cin >> x, arr[x] = i;
  for (int i = 2; i <= a; i++) ans += abs(arr[i] - arr[i - 1]);
  cout << ans << endl;
  return 0;
}
