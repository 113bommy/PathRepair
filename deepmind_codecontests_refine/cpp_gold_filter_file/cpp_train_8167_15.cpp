#include <bits/stdc++.h>
using namespace std;
bool check(int current, int arr[], int t, int n) {
  if (current > t) return false;
  if (current == t) return true;
  return check(current + arr[current], arr, t, n);
}
int main() {
  int n, t, c = 1;
  cin >> n >> t;
  int arr[n];
  for (int i = 1; i < n; i++) cin >> arr[i];
  if (check(c, arr, t, n))
    cout << "YES";
  else
    cout << "NO";
}
