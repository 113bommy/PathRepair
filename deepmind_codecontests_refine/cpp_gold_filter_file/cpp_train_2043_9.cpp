#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long)8e18;
const long long int MOD = 998244353;
int n, k, arr[300000];
void mergesort(int l, int r) {
  if (l + 1 == r) return;
  if (k < 2) return;
  k--;
  k--;
  int mid = (l + r) / 2;
  if (mid > l)
    swap(arr[mid - 1], arr[mid]);
  else
    swap(arr[l], arr[r]);
  mergesort(l, mid);
  mergesort(mid, r);
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n + 1; i++) arr[i] = i + 1;
  k--;
  mergesort(0, n);
  if (k > 0)
    cout << -1 << '\n';
  else {
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
  }
  return 0;
}
