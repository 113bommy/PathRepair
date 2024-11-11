#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> arr;
void foo(int l, int r) {
  if (k <= 1) {
    return;
  }
  if (l + 1 >= r) {
    return;
  }
  int mid = (l + r) / 2;
  if (mid - 1 >= 0) {
    swap(arr[mid - 1], arr[mid]);
    k -= 2;
    foo(l, mid);
    foo(mid, r);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  arr = vector<int>(n);
  for (int i = (0); i < (n); i++) {
    arr[i] = i + 1;
  }
  foo(0, n);
  if (k != 1) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = (0); i < (n); i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
