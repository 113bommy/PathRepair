#include <bits/stdc++.h>
using namespace std;
int frq[1000];
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int x = 0, r = 1;
  int l;
  while (r < n && arr[r] <= arr[x]) {
    frq[x]++;
    r++;
    x++;
  }
  for (int i = 1; i < n - 1; i++) {
    x = i;
    r = i + 1;
    l = i - 1;
    while (l >= 0 && arr[l] <= arr[x]) {
      frq[i]++;
      l--;
      x--;
    }
    x = i;
    while (r < n && arr[r] <= arr[x]) {
      frq[i]++;
      r++;
      x++;
    }
  }
  x = n - 1;
  l = n - 2;
  while (l >= 0 && arr[l] <= arr[x]) {
    frq[n - 1]++;
    l--;
    x--;
  }
  sort(frq, frq + n);
  cout << frq[n - 1] + 1;
  return 0;
}
